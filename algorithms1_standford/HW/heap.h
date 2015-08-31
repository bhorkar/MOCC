#ifndef _HEAP_H_
#define _HEAP_H_
//        MAX_HEAP
void MAX_HEAPIFY(short *A,short i)        {
        short left=2*i,right=2*i+1,larger,tmp;
        if ((left<=A[0])&&(A[left]>A[i]))
          larger = left;
        else
          larger = i;
        if ((right<=A[0])&&(A[right]>A[larger]))
          larger = right;
        if (larger != i)        {
          tmp = A[larger]; A[larger] = A[i]; A[i] = tmp;
          MAX_HEAPIFY(A,larger);
        }
}
short EXTRACT_MAX(short *A)        {
  short max = A[1];
  A[1] = A[A[0]--];
  MAX_HEAPIFY(A,1);
  return max;
}
void HEAP_INCREASE_KEY(short *A,short i,short key)        {
  short tmp;
  A[i] = key;
  while ((i>1)&&(A[i/2]<A[i]))        {
        tmp = A[i]; A[i] = A[i/2]; A[i/2] = tmp;
        i = i/2;
  }
}
void MAX_HEAP_INSERT(short *A,short key)        {
  A[0]++;
  HEAP_INCREASE_KEY(A,A[0],key);
}
//        MIN_HEAP
void MIN_HEAPIFY(short *A,short i)        {
        short left=2*i,right=2*i+1,smaller,tmp;
        if ((left<=A[0])&&(A[left]<A[i]))
          smaller = left;
        else
          smaller = i;
        if ((right<=A[0])&&(A[right]<A[smaller]))
          smaller = right;
        if (smaller != i)        {
          tmp = A[smaller]; A[smaller] = A[i]; A[i] = tmp;
          MIN_HEAPIFY(A,smaller);
        }
}
short EXTRACT_MIN(short *A)        {
  short min = A[1];
  A[1] = A[A[0]--];
  MIN_HEAPIFY(A,1);
  return min;
}
void HEAP_DECREASE_KEY(short *A,short i,short key)        {
  short tmp;
  A[i] = key;
  while ((i>1)&&(A[i/2]>A[i]))        {
        tmp = A[i]; A[i] = A[i/2]; A[i/2] = tmp;
        i = i/2;
  }
}
void MIN_HEAP_INSERT(short *A,short key)        {
  A[0]++;
  HEAP_DECREASE_KEY(A,A[0],key);
}
#endif
