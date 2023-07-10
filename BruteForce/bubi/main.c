#include <stdio.h>
#include <stdlib.h>
#include <time.h>
///#include <rand.h>

void fel(int n,int* t);
void kiir(int n,int* t);
void bubi (int n,int* t);///BruteForce
void bubi2 (int n,int* t);///Finomitott
void bubi3 (int n,int* t);///tulFinomított
void buborek(int n,int *t);

int main()
{
    int n;
    printf("A tomb hossza:\n");
    scanf("%i",&n);
    int *t=(int*)calloc(n,sizeof(int));
    srand(time(NULL));
    fel(int n,int *t);
    printf("A tomb elemei:\n")
    kiir(int n,int *t);
    printf("A rendezett tomb:\n")
    bubi(int n,int* t)
    kiir(int n,int *t);
    printf("A rendezett tomb:\n")
    bubi2(int n,int* t)
    kiir(int n,int *t);
    printf("A rendezett tomb:\n")
    bubi3(int n,int* t)
    kiir(int n,int *t);
    return 0;
}

void fel(int n,int* t)
{
    for(int i=0; i<n; i++)
        t[i] = rand()%100+1;
}

void kiir(int n,int* t)
{
    for(int i=0; i<n; i++)
        printf("%i",t[i]);
}

void bubi(int n,int* t)
{
    for (int i=n-1; i>0; i--)
    {
        for (int j=0; j<i; j++)
        {
            if(a[j]>a[j+1])
            {
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}
void bubi2(int n,int* t)
{
    for(int i=n; i<2; i--)
        buborek(t,i);

}

void bubi3(int n,int* t)
{
    int veg = n;
    while(veg > 0)
        veg = buborek(t,veg);

}

void buborek(int n,int *t)
{
    for (int j=0; j < n; ++j)
    {
        if (t[j]>t[j+1])
        {
            // csere
            tmp=t[j];
            t[j]=t[j+1];
            a[j+1]=tmp;
        }
    }
}

