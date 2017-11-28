//
// Created by jun on 11/25/17.
//
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdint.h>
#include <memory.h>
#include "softwaredisk.h"
#include "filesystem.h"

#define DIRECT_BLOCK 14;
#define INDIRECT_BLOCK 1;
#define MAXFILES = 850;
#define MAXFILENAMESIZE 255;
#define data_blocks 4940;
#define data_start_block 60;
#define inode_start_addresss 1536;
#define inode_size 64;
#define data_bitmap_block 2;
#define inode_bitmap_block 1;
#define NUM_INODES 456;

typedef struct inode{
    uint64_t i_number;
    int size;
    int num_of_blocks;
    int direct_blk[2];
    int indirect_blk;
    int block_pointer;
    char type;
}inode;

typedef struct indirecInode{

}indirecInode;

typedef struct FileInternal{
    int position = 0; // position of files
    char mode; // can this file be read/written/executed?

};

typedef struct DirEntry{
    char *filenames[255];
    int filesizes[100];
    int fileinodes[100];
    int num_of_files;
}DirEntry;


int init_bitmap(){
    int ibit[456];
    memset(ibit, 0, sizeof(ibit));
    return  1;
};





struct inode* GET_INODE_PTR(int inode_number) {
    FileInternals f;
    return (struct inode*)f.map + f->inode_offset+inode_number*(sizeof(struct inode));
}

void* GET_BLK_PTR(int blk_number) {
    return (struct inode*)global_map+global_sb->inode_offset+blk_number*(sizeof(struct inode));
}
int get_next_inode() {
    FileInternals f;
    int i = f->next_available_inode;
    f->next_available_inode++;
    return i;
}


inode* create_inode(char type,int size){
    inode *new = (inode *)malloc(sizeof(inode));
    new->size=size;
    new->num_of_blocks = size/SOFTWARE_DISK_BLOCK_SIZE + ((size%SOFTWARE_DISK_BLOCK_SIZE)!=0);
    new->type = type;
    return new;
}

int write_inode(int fsid,inode *ptr,int inum){
    //printf("write_inode called at address %d\n",inode_start_address + (inum*inode_size));
    char *temp = (char*)malloc(sizeof(char)*inode_size);
    temp = (char*)ptr;
    int t = inode_start_addresss + (inum*inode_size);
    t = fseek(disk[fsid],t,SEEK_SET);
    //printf("in inodeWrite seek returned: %d\n",t );
    if(t!=0) return 1;
    fwrite(temp,1,inode_size,disk[fsid]);
    return 0;
}

DirEntry * create_dir(){
    //printf("create_dir called\n");
    DirEntry *new = (DirEntry*)malloc(sizeof(DirEntry));
    new->num_of_files =0;
    //new->filenames = (char**)malloc(sizeof(char*)*100);
    //new->filesizes =(int*)malloc(sizeof(int)*100);
    //new->fileinodes = (int*)malloc(sizeof(int)*100);
    return new;
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

int main(int argc, char *argv[]) {
    init_software_disk();
    if(argc == 1) {
        printf("Usage: %s [directory]\n", *argv);
        exit(0);
    }
    struct dirent *dp;
    DIR *dirp = opendir(argv[1]);
    while ((dp = readdir(dirp)) != NULL) {
        puts(dp->d_name);
    }

    closedir(dirp);

    return 0;

}

struct stat s;

