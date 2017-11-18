//
// Created by jun on 11/14/17.
//


#include "fcntl.h"
#include "filesystem.h"
#include "softwaredisk.h"
#include "softwaredisk.c"

struct Node{
    int data;
    struct Node *next;
};


FSError fsError;

// open existing file with pathname 'name' and access mode 'mode'.  Current file
// position is set at byte 0.  Returns NULL on error. Always sets 'fserror' global.
File open_file(char *name, FileMode mode){
    FileInternals *f;
    fsError = FS_NONE;
    int i, fd;
    
    if (mode != READ_ONLY) return NULL;
    
    if (mode == READ_ONLY) {
        fd = open(name, O_RDONLY);
        if (fd < 0){
            fserror = FS_FILE_NOT_FOUND;
            return NULL;
        }
        f->fd = fd;
    }
    return f;
}

// create and open new file with pathname 'name' and access mode 'mode'.  Current file
// position is set at byte 0.  Returns NULL on error. Always sets 'fserror' global.
File create_file(char *name, FileMode mode){
    FileInternals *f;
    fsError = FS_NONE;
    int i, fd;
    
    if (mode != READ_WRITE) return NULL;
    //no-flag added
    f = malloc(NUM_BLOCKS * SOFTWARE_DISK_BLOCK_SIZE);

    }
    if (mode == READ_WRITE) {
        fd = creat(name, O_RDWR);
        f->fd = fd;
    }

    

}

// close 'file'.  Always sets 'fserror' global.
void close_file(File file){
    fsError = FS_NONE;
    
}

// read at most 'numbytes' of data from 'file' into 'buf', starting at the
// current file position.  Returns the number of bytes read. If end of file is reached,
// then a return value less than 'numbytes' signals this condition. Always sets
// 'fserror' global.
unsigned long read_file(File file, void *buf, unsigned long numbytes){

}

// write 'numbytes' of data from 'buf' into 'file' at the current file position.
// Returns the number of bytes written. On an out of space error, the return value may be
// less than 'numbytes'.  Always sets 'fserror' global.
unsigned long write_file(File file, void *buf, unsigned long numbytes){

}

// sets current position in file to 'bytepos', always relative to the beginning of file.
// Seeks past the current end of file should extend the file. Always sets 'fserror'
// global.
void seek_file(File file, unsigned long bytepos){

}

// returns the current length of the file in bytes. Always sets 'fserror' global.
unsigned long file_length(File file){

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
