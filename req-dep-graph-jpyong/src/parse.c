#include "../include/parse.h"
#include <stdio.h>
#include <string.h>
//#include <regex.h> research regex in minGW, may need emulator

void scrapeFileName(char* filePath) {
    int len = strlen(filePath);

    if (len > 0 && (filePath[len-1] == '\n')) {
      filePath[len-1] = '\0'; //removing the new line character
    }

    char* fSlash = strrchr(filePath, '/'); //return a pointer to the last occurence of the frontslash
    char* bSlash = strrchr(filePath, '\\'); //return a pointer to the last occurence of the backslash
    if (bSlash != NULL && ((fSlash == NULL) || bSlash > fSlash)) {
      fSlash = bSlash; //if back slashes are used, set fSlash to the same point as bSlash
    }

    if (fSlash != NULL) {
      printf("Filename: %s \n", fSlash+1);
    } else {
      printf("Filename: %s \n", filePath); //if no slashes the entire input is the file name
    }
}

void parse_SRS(char* file) {
    //this function is currently a stub, but it will be implemented at a later date.
}
