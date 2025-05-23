#include <stdio.h>

#include "parse.h"
#include "tree.h"

int main() {

  FILE *f; 
  char filePath[100];

  printf("Please select a file (enter complete path to the file) for processing: ");
  scanf("%99s", filePath);

  f = fopen(filePath, "r");
  if (f == NULL) {
    printf("Error opening file");
    return 1;
  }

  //scraping & printing the file name from input
  scrapeFileName(filePath);

  //print first three lines
  char ch;
  int i = 0;
  while (i < 3) {
      ch = fgetc(f);
      putchar(ch);
      if (ch == '\n') {i++;}
  }
  

  fclose(f);
  return 0;

}
