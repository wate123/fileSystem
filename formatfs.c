//
// Created by jun on 11/25/17.
//
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "softwaredisk.h"

#define DIRECT_BLOCK 14;
#define INDIRECT_BLOCK 1;
#define MAXFILES = 850;
#define MAXFILENAMESIZE 255;
#define inode_start_addresss = 1536;
struct inode{

};

struct indirecInode{

};

struct i
struct FileInternal{
    int position = 0; // position of files
    char mode; // can this file be read/written/executed?

};

struct DirEntry{

};

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

