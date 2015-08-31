#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include "heap.h"
const char INFILE[] = "Median.txt";
#define MAX        10000
short A1[10001],A2[10001];

short RETURN_MEDIAN(short *A1,short *A2,short x)        {
  if (x<A2[1])
        MAX_HEAP_INSERT(A1,x);
  else
        MIN_HEAP_INSERT(A2,x);
  if (A1[0]-A2[0]>1)        
        MIN_HEAP_INSERT(A2,EXTRACT_MAX(A1));
  if (A2[0]>A1[0])        
        MAX_HEAP_INSERT(A1,EXTRACT_MIN(A2));
  return A1[1];
}


int main()        {
  int m=0;
  A1[0] = 1; A1[1] = 0;
  A2[0] = 1; A2[1] = 20000;
  char line[10];
  FILE *fp = fopen(INFILE,"r");
  while (fgets(line,10,fp))        
        m = (m + RETURN_MEDIAN(A1,A2,atoi(line))) % 10000;
  printf("%d\n",m);
}
