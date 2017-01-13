/*---------------------------------

  FRAMED
  Write a program that, given a string S, outputs a pretty-printed version of S 
  inside of a boxed frame made up of # characters, with each word on its own line.

  ##########
  # Hello  #
  # world  #
  # in     #
  # a      #
  # frame. #
  ##########

 ---------------------------------*/

#include <cs50.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
  char *line = GetString();
  char *lineCopy = malloc((strlen(line) + 1) * sizeof line[0]);
  memcpy(lineCopy, line, strlen(line) + 1);

  // find the widest string
  char delim[2] = " ";
  int  width = 0;
  
  char *token = strtok(lineCopy, delim);
  
  while (token != NULL) {
    if ((int)strlen(token) > width) width = (int)strlen(token);
    token = strtok(NULL, delim);
  }
  
  // render the table
  char *border = "######################################################";
  printf ("%.*s\n", width + 4, border);
  
  token = strtok(line, delim);
  
  while (token != NULL) {
    printf("# %-*s #\n", width, token);
    token = strtok(NULL, delim);
  }
  
  printf ("%.*s\n", width + 4, border);
}