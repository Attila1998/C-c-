#include <stdio.h>
#include <stdlib.h>

int main()
{
 int *a,n;
 printf("A tomb merete: ");
 scanf("%i ",&n);
  a=(int*)malloc(n*sizeof(int));
  printf("A tomb elemei: ");
    for(int i=0;i<n;i++){scanf("%i ",a[i]);}
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++){printf("%i ,",a[i]);}
    free(a);
    return 0;

}


void quicksort(int*t, int left, int right)
{
    int j;
    if(left<right)
    {
        j=Partition(t,left,right);
        quicksort(t,left,j-1);
        quicksort(t,j+1,right);
    }
}

int Partition(int*a, int left, int right)
{
    int pivot,i,j,t;
    pivot=a[left];
    i=left; j=right+1;

    while(1)
    {
        do ++i; while(a[i]<=pivot && i<=right);
        do --j; while(a[j]>pivot);
        if(i>=j)
        {
            break;
        }
        t=a[i];
        a[i]=a[j];
        a[j]=t;
    }
    t=a[left];
    a[left]=a[j];
    a[j]=t;
    return j;
}
