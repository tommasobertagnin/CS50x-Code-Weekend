/*---------------------------------

  AABB Collision Detection
  Write a program that reads values describing two AABBs from standard input and
  prints the area of their overlapping region or 0.00 if they do not overlap.

 ---------------------------------*/
 
#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

double min (double a, double b);
double max (double a, double b);
double* GetStrAsArray (int length);

int main(void)
{
  double* rectA = GetStrAsArray(4);
  double* rectB = GetStrAsArray(4);

  double x_overlap = max(0, min(rectA[0] + rectA[2], rectB[0] + rectB[2]) - max(rectA[0], rectB[0]));
  double y_overlap = max(0, min(rectA[1] + rectA[3], rectB[1] + rectB[3]) - max(rectA[1], rectB[1]));
  double overlapArea = x_overlap * y_overlap;
  
  printf("%0.2f\n", overlapArea);
}

double min (double a, double b) {
  return a < b ? a : b;
}

double max (double a, double b) {
  return a > b ? a : b;
}

double* GetStrAsArray (int length) {
  char* line = GetString();
  
  char delim[2] = " ";
  char* tok = strtok(line, delim);
  double* arr = malloc(sizeof(double) * length); 
  
  for (int i = 0; i < length; i++) {
    arr[i] = atof(tok);
    tok = strtok(NULL, delim);
  }
  
  return arr;
}