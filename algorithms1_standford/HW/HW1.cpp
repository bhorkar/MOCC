#include <cstdlib>
#include <iostream>
#include <stdio.h>
#define SIZE 100000

using namespace std;

long long splitInv(long *arr, long l, long u)
{
     long *tarr = new long[u-l+2];
     long i=l, j=(u-l)/2+l+1, k;
     long long count=0;
     for(k=1; (k<=u-l+1) && (i<=(u-l)/2+l) && (j<=u); k++)
     {
              if(arr[i]<arr[j]) tarr[k]=arr[i++];
              else
              {
                  tarr[k]=arr[j++];
                  count=count+((u-l)/2+l-i+1);
              }
     }
     for(; k<=u-l+1 && i<=(u-l)/2+l; k++) tarr[k]=arr[i++];
     for(; k<=u-l+1 && j<=u; k++) tarr[k]=arr[j++];
     for(k=1, i=l ; k<=u-l+1 && i<=u; k++, i++) arr[i]=tarr[k];
     delete tarr;
     return count;
}

long long numInv(long *arr, long l, long u)
{
     if(u<=l) return 0;
     return numInv(arr, l, (u-l)/2+l) + numInv(arr, (u-l)/2+l+1, u) + splitInv(arr, l, u);
}

int main(int argc, char *argv[])
{
    long *arr=new long[SIZE+1];
    char a[10];
    FILE *f=fopen("IntegerArray.txt","r");
    for(long i=1; i<=SIZE; i++)
    {
            fgets(a,10,f);
            arr[i]=atol(a);
    }
    fclose(f);
    cout<<"Number of Inversions: "<<numInv(arr,1,SIZE)<<endl;
    delete arr;
    system("PAUSE");
    return EXIT_SUCCESS;
}
