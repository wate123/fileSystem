//
// Created by jun on 11/14/17.
//


#include "filesystem.h"
#include "softwaredisk.h"
#include "softwaredisk.c"
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <memory.h>
#include <values.h>
#include <errno.h>
#include "formatfs.c"


//get attribute of files
int getAttr(const char *path, struct stat *statbuf)
{
    int path_len = (int) strlen(path);
    printf("%s: %s\n", __FUNCTION__, path);

    if ( (path_len == 1) && path[0] == '/') {
        statbuf->st_mode = S_IFDIR | S_IRWXU | S_IRWXG | S_IRWXO;
        statbuf->st_uid = 0;
        statbuf->st_gid = 0;
        statbuf->st_nlink = 1;
        statbuf->st_ino = 0;
    } else {
        int i = 0;
        while(i<PATH_MAX){
            int size;
            //int block_count;
            statbuf->st_mode = (S_IFREG | S_IRWXU | S_IRWXG | S_IRWXO) & ~S_IXUSR & ~S_IXGRP & ~S_IXOTH;
            statbuf->st_nlink = 1;
            statbuf->st_uid = 0;
            statbuf->st_gid = 0;
            statbuf->st_size = size;
            //  statbuf->st_blocks = block_count;               // number of 512B blocks allocated
        }
    }

    return 0;
}

FSError fserror;

// open existing file with pathname 'name' and access mode 'mode'.  Current file
// position is set at byte 0.  Returns NULL on error. Always sets 'fserror' global.
File open_file(char *name, FileMode mode){
//    if (mode != READ_ONLY) return NULL;
//    FileInternals *f;
//    fserror = FS_NONE;
//    int fd;
//    fd = open(name, O_RDONLY);
//    if (fd < 0){
//        fserror = FS_FILE_NOT_FOUND;
//        return NULL;
//    }
//    f->fd;
//    return f;
    int retstat = 0;
    int fd;

    if(fd == -1) {
        return -errno;
    }

    return retstat;
}

// create and open new file with pathname 'name' and access mode 'mode'.  Current file
// position is set at byte 0.  Returns NULL on error. Always sets 'fserror' global.
File create_file(char *name, FileMode mode){
    if (mode != READ_WRITE) return NULL;
    File f;
    f = malloc(NUM_BLOCKS * SOFTWARE_DISK_BLOCK_SIZE);
    fserror = FS_NONE;
    //no-flag added
    if(f->fd < 0 ){
        fserror = FS_OUT_OF_SPACE;
        return NULL;
    }
    return f;

}

// close 'file'.  Always sets 'fserror' global.
void close_file(File file){
    if (file->f && close(file->fd) == 0){
        fserror = FS_NONE;
    }
}

// read at most 'numbytes' of data from 'file' into 'buf', starting at the
// current file position.  Returns the number of bytes read. If end of file is reached,
// then a return value less than 'numbytes' signals this condition. Always sets
// 'fserror' global.
unsigned long read_file(File file, void *buf, unsigned long numbytes){
    struct inode *inode_ptr = GET_INODE_PTR(inode_number);
    void *local_buf = buf;
    unsigned long read_count = 0L;

    int block_id = calc_data_block_id(offset);
    int block_offset = calc_data_block_offset(offset);
    int ret = read_sd_block(local_buf,);

    while(1) {
        local_buf += ret;
        read_count += ret;
        block_id++;
        if(read_count>=count)
            break;
        //no more offset
        ret = read_from_block(inode_ptr, block_id, 0, local_buf, count-read_count);
    }
    return read_count;
}

// write 'numbytes' of data from 'buf' into 'file' at the current file position.
// Returns the number of bytes written. On an out of space error, the return value may be
// less than 'numbytes'.  Always sets 'fserror' global.
unsigned long write_file(File file, void *buf, unsigned long numbytes){
    unsigned long bytes_written=0L;
    char save[numbytes];

    fserror=FS_NONE;
    if(! file->f){
        fserror=FS_FILE_NOT_OPEN;
        return 0L;
    }
    bytes_written = (unsigned long) write(file->fd, buf, numbytes);
    return bytes_written;
}

// sets current position in file to 'bytepos', always relative to the beginning of file.
// Seeks past the current end of file should extend the file. Always sets 'fserror'
// global.
void seek_file(File file, unsigned long bytepos){
    if (! file->f || )
}

// returns the current length of the file in bytes. Always sets 'fserror' global.
unsigned long file_length(File file){
    struct stat buf;
    fstat(file->fd, &buf);
    return (unsigned long) buf.st_size;
}

// deletes the file named 'name', if it exists and if the file is closed.
// Fails if the file is currently open. Returns 1 on success, 0 on failure.
// Always sets 'fserror' global.
int delete_file(char *name){

}

// determines if a file with 'name' exists and returns 1 if it exists, otherwise 0.
// Always sets 'fserror' global.
int file_exists(char *name){

}

// describe current filesystem error code by printing a descriptive message to standard
// error.
void fs_print_error(void){

}
