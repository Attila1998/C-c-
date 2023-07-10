#include <stdio.h>
#include <stdlib.h>

int binarySearch(int* a,int ,int ,int );

int main()
{
    FILE* fin = fopen("be.txt","rt");
    if(!fin){printf("File Hiba!\n");return 0;}
    int n,num;
    fscanf(fin,"%i",&n);
    int *arr = (int*)calloc(n,sizeof(int));
    if(!arr){printf("Array hiba!");return 0;}

    for(int i = 0 ; i < n ; i ++)
    {
        fscanf(fin,"%i",&arr[i]);
    }

        for(int i = 0 ; i < n ; i ++)
    {
        printf("%i ",arr[i]);
    }
    printf("\n");
    printf("Whats the numeber you lookin for?\n");
    scanf("%i",&num);

    if (binarySearch(arr,0,n,num) != -1)
    {
        printf("The numbers location: %i\n",binarySearch(arr,0,n,num)+1);
    }
    else
        printf("The number can't be found in the Array!\n");
    return 0;
}

int binarySearch(int* arr,int left,int right,int num)
{
       if (right >= left) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == num)
            return mid;
        if (arr[mid] > num)
            return binarySearch(arr, left, mid - 1, num);
        return binarySearch(arr, mid + 1, right, num);
    }

    return -1;
}
