#include "parse.h"
#include <stdio.h>
#include <string.h>
#include <regex.h>

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


void parse_SRS(char* filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening the file, blowing up\n");
    return;
  }

  regex_t regex;
  const char *pattern = "REQ-[A-Z]{2}-[A-Z]{4}-[0-9]{4}";

  if (regcomp(&regex, pattern, REG_EXTENDED)) {
    printf("Could not compile regex\n");
    return;
  }

  char line[MAX_LINE]; //longest allowed line is 1024 characters long
  while (fgets(line, sizeof(line), file)) {
    const char *cursor = line; //created a cursor to iterate through every character per line
    regmatch_t matches[1]; //regmatch_t allows us to look for the substring REQ-XX-XXXX-NNNN
    
    while(regexec(&regex, cursor, 1, matches, 0) == 0) { //running regexec on each string to look for matches
      int start = matches[0].rm_so; //address of start of matched string
      int end = matches[0].rm_eo; //address of end of matched string

      char tag[TAG_LENGTH]; //initializing tagged string to 0
      strncpy(tag, cursor+start, end-start); //copying found req into tag
      tag[end - start] = '\0'; //adding termination character

      if (strncmp(tag + 13, "0000", 4) != 0) {  //filter out REQ-XX-YYYY-0000
         printf("Found: %s\n", tag); 
      }

      cursor += end; //move past the last match
    }
  }

    regfree(&regex);
    fclose(file);

}
