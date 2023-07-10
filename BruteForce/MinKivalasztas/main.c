#include <stdio.h>
#include <stdlib.h>
#include <time.h>
///#include <rand.h>

void fel(int n,int* t);
void kiir(int n,int* t);
void rendez(int n,int* t);///BruteForce
void rendez2(int n,int* t);///Finomitott
void beszur(int* t,int n)
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
    rendez(int n,int *t);
    printf("A rendezett tomb:\n")
    kiir(int n,int *t);
    rendez2(int n,int* t);
    printf("A finomitott rendezes utan a tomb:\n")
    kiir(int n,int *t);
    return 0;
}

void fel(int n,int* t)
{
    for(int i=0;i<n;i++)
        t[i] = rand()%100+1;
}

void kiir(int n,int* t)
{
    for(int i=0;i<n;i++)
        printf("%i",t[i]);
}

void rendez(int n,int* t)
{
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+;j<n;j++)
            if(t[min] > t[j])
        {
            min = j;
            int veder = t[i];
            t[i] = t[min];
            t[min] = veder;
        }
    }
}

void rendez2(int n,int* t)
{
    if(n>1)
    rendez2(n-1,t)
    beszur(n,t)
}

void beszur(int n,int *t)
{j=0;
    for(int i=j;i<n-1;i++)
        if(a[i]<ai+1)
    {
            int veder = t[i];
            t[i] = t[i+1];
            t[i+1] = veder;
            j++;
    }
}
