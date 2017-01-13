/*---------------------------------

  ORDINARY ORDINALS
  Write a program that, given a string S of space-separated words
  via standard input, finds the position of the word "cat".

 ---------------------------------*/

#include <cs50.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
  char *line = GetString();
  
  if (!line) {
    printf("There is no box");
    return 0;
  }
  
  int pos = 0;
  int ones, tens;
  char *suffix = "th";
  char s[2] = " ";
  char *token;

  token = strtok(line, s);
  
  while (token != NULL) {
    pos++;
    
    if (strcmp(token, "cat") == 0) {
      ones = pos % 10;
      tens = (pos / 10) % 10;
      if (ones == 1 && tens != 1) suffix = "st";
      if (ones == 2 && tens != 1) suffix = "nd";
      if (ones == 3 && tens != 1) suffix = "rd";
      
      printf("The cat is the %d%s item in the box", pos, suffix);
      return 0;
    }
    
    token = strtok(NULL, s);
  }
  
  printf("No cat yet");
  return 0;
}