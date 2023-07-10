#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void feltolt(int *,int);
void kiir(int*,int);
void csere(int*,int,int);
void Selection(int*,int);
void mergeSort(int*,int,int );
void merge(int*,int,int,int );


int main()
{
//változók deklarálása
    int *t;
    int n,i;
    printf("Adja meg a tomb meretet!\n");
    scanf("%i",&n);
    srand(time(NULL));
//dinamikus helyfoglalás
    t = (int*)calloc(n,sizeof(int));

//tomb elemszámának a beolvasása billentyûzetrõl

    feltolt(t,n);//véletlenszerûen (rand())
    printf(" \nRendezes elott\n");
    kiir(t,n);

   /// printf("Selection Sort:\n");
   /// Selection(t,n);
   /// printf("MergeSort\n");
   /// mergeSort(t,0,n);
    kiir(t,n);
    printf(" \n");
}
void feltolt(int *t, int n)
{
    for(int i=0; i<n; i++)
        t[i] = rand()%100+1;
}

void kiir(int *t,int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%i ",t[i]);
    }
    printf("\n");
}

void csere(int* t,int a,int b)
{
    int x;
    x = t[a];
    t[a] = t[b];
    t[b] = x;
}

void Selection(int *t,int n)
{
    for(int i=0; i<n-1; i++)
    {
        int min=i;
        for(int j=i; j<n; j++)
            if(t[min] > t[j])
            {
                //min = j;
                csere(t,min,j);
            }

    }
}


void merge(int* arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int* arr, int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}
