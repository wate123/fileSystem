//
// Created by jun on 11/25/17.
//
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdint.h>
#include <memory.h>
#include <tgmath.h>
#include <time.h>
#include "softwaredisk.h"
#include "filesystem.h"

#define DIRECT_BLOCK 13;
#define INDIRECT_BLOCK 1;
#define MAXFILES = 850;
#define MAXFILENAMESIZE 255;
#define data_blocks 4940;
#define data_start_block 60;
#define inode_start_addresss 1536;
#define inode_size 32;
#define data_bitmap_block 2;
#define inode_bitmap_block 1;
#define NUM_INODES 456;
char global_hd_file[850];
char *global_map;

//contain inode number, mode, timestamp, type, size, number of block of inode, number of direct block,
// one indirect block
typedef struct inode{
    uint64_t i_number; // number of Inode
    char mode; // can this file be read/written/executed?
    time_t i_mtime;
    int i_type;
    int i_size;
    int i_blocks;
    int direct_blk[14];
    int indirect_blk;
    int file_num;
}inode;

/*
 * information about inode, inode offset, data offset,  next available inode, next available block
 */
typedef struct FileInternal{
    int inode_offset;
    int data_offset;
    int next_available_inode;
    int next_available_blk;
};

struct FileInternal* global_node;
/*
 * inode number.
 */
typedef struct dir_mapping{
    char dir[10];
    int inode_number;
}DIR_NODE;

//bitmap struct
typedef struct {
    char* bits;
    int size;
}bitvector;

//Create a bitmap with n_bits
bitvector* create_bitvec(int n_bits) {
    bitvector* vec = (bitvector*)malloc(sizeof(bitvector));
    int size = sizeof(bitvector) * ceil(n_bits/8.0);
    vec->size = size;
    vec->bits = (char*)malloc(size);
    return vec;
}

//Destroy the bit map
void destroy_bitvec(bitvector *vec) {
    free(vec->bits);
    free(vec);
}

// set  i -th bit to 1 or 0
void set_bit(bitvector* vec, int index, int bit) {
    int byte = index >> 3;
    int n = sizeof(index)*8-3;
    int offset = ((unsigned) index << n) >> n;
    if (bit) {
        vec->bits[byte] |= 1 << (7-offset);
    } else {
        vec->bits[byte] &= ~(1 << (7-offset));
    }
}

// get value of i-th bit
int get_bit(bitvector* vec, int index) {
    int byte = index >> 3;
    int n = sizeof(index)*8-3;
    int offset = ((unsigned) index << n) >> n;
    if (vec->bits[byte] & (1 << (7- offset))) {
        return 1;
    } else {
        return 0;
    }
}
/*
 * find the next inode
 */
int get_next_inode() {
    int i = global_node->next_available_inode;
    global_node->next_available_inode++;
    return i;
}

/*
 * Get the inode pointer
 */
struct inode* GET_INODE_PTR(int inode_number) {
    return (struct inode*)global_map+ global_node->inode_offset+inode_number*(sizeof(struct inode));
}

/*
 * Get block pointer
 */
void* GET_BLK_PTR(int blk_number) {
    return (struct inode*)global_map+global_node->inode_offset+blk_number*(sizeof(struct inode));
}

/*
 * find the next block
 */
int get_next_block() {
    int i = global_node->next_available_blk;
    global_node->next_available_blk++;
    return i;
}

//add entry of directory
void add_entry(int dir_inode, const char *entry_name, int entry_inode) {
}

//create directory base on parent inode and the directory name
int create_directory(int parent_inode, const char *dir_name) {
    // allocate inode
    int child_inode = get_next_inode();

    // initialize the inode structure
    struct inode *inode_ptr = GET_INODE_PTR(child_inode);
    inode_ptr->i_number = (uint64_t) child_inode;
    time(&inode_ptr->i_mtime);
    inode_ptr->i_type = 0;
    inode_ptr->i_size = 0;
    inode_ptr->i_blocks = -1;
    inode_ptr->direct_blk[0] = 0;
    inode_ptr->direct_blk[1] = 0;
    inode_ptr->indirect_blk = 0;
    inode_ptr->file_num = 0;

    // add item into parent_inode
    add_entry(parent_inode, dir_name, child_inode);
    // add . and .. into the child_inode
    add_entry(child_inode, ".", child_inode);
    add_entry(child_inode, "..", parent_inode);
    return child_inode;
}

// create file with parent inode and name
int create_file_with_inode(int parent_inode, const char *filename) {
    int child_inode = get_next_inode();

    // initialize the inode structure
    struct inode *inode_ptr = GET_INODE_PTR(child_inode);
    inode_ptr->i_number = (uint64_t) child_inode;
    time(&inode_ptr->i_mtime);
    inode_ptr->i_type = 1;
    inode_ptr->i_size = 0;
    inode_ptr->i_blocks = -1;
    inode_ptr->direct_blk[0] = 0;
    inode_ptr->direct_blk[1] = 0;
    inode_ptr->indirect_blk = 0;
    inode_ptr->file_num = 0;

    add_entry(parent_inode, filename, child_inode);
    return child_inode;
}

// calculate the block_num after the offset
int calc_data_block_id(int offset) {
    return SOFTWARE_DISK_BLOCK_SIZE / offset;
}

// calcuate the amount of offset in the first blk for writing
int calc_data_block_offset(int offset) {
    return offset - (SOFTWARE_DISK_BLOCK_SIZE / offset)*SOFTWARE_DISK_BLOCK_SIZE;
}

// get a pointer which store the block_number of the block in inode
int* get_blk_in_inode(struct inode *inode, int blk_number) {
    if (blk_number == 0)
        return &inode->direct_blk[0];
    else if (blk_number == 1)
        return &inode->direct_blk[1];
    else {
        if (inode->indirect_blk < 0) {
            perror("ERROR: indirect_blk not allocated in get_blk_in_inode()\n");
            return NULL;
        }
        int *blk = (int*)GET_BLK_PTR(inode->indirect_blk);
        return blk+(blk_number-2);
    }
}

/**
 * @brief Find file or directory in a directory
 * @retval -1 File not found
 * @retval -2 Not a directory
 */
int _find_inode(int inode, char *dir_name) {
    struct inode *inode_ptr = GET_INODE_PTR(inode);
    // check if the inode is a directory
    if(inode_ptr->i_type != 0) {
        return -2;      // error: this is not a directory
    }
    // loop each dir_mapping record and compare the name
    int i = 0;
    do {
        struct dir_mapping map;
        if (strcmp(map.dir, dir_name)==0) {
            return map.inode_number;    // found
        }
        i++;
    } while (1);
}

//find inode base on the path
int find_inode(const char *path) {
    // root dir
    int inode = 0;
    char inode_name[10] = "/";
    char *pch;
    char tmp_path[65535];
    strncpy(tmp_path, path, 65535);
    pch = strtok(tmp_path, "/");
    while (pch != NULL) {
        // find the child item in the current directory *inode
        inode = _find_inode(inode, pch);
        if (inode==-1) {
            fprintf(stderr, "Error: cannot find '%s' in '%s'.\n", pch, inode_name);
            return -1;
        } else if (inode==-2) {
            fprintf(stderr, "Error: '%s' is not a directory.\n", pch);
            return -1;
        }
        pch = strtok(NULL, "/\\");
    }
    return inode;
}


int main(int argc, char *argv[]) {
    init_software_disk();
    return 0;

}

