#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void feltolt(int,int**);
void kiir(int,int**);

int main()
{

    int n,i,j;
//FILE* fin = fopen("Matrix.txt","rt");
    scanf("%i",&n);
    printf("n erteke:%i \n",n);

    int**t;
    t=(int**)calloc(n,sizeof(int*));
    for(i=0; i<n; i++)
    {
        t[i]=(int*)calloc(n,sizeof(int));
    }

printf("0-as Tomb:\n");
kiir(n,t);


feltolt(n,t);
printf("Veleteln matrix:\n");
kiir(n,t);
    return 0;
}

void feltolt(int n, int**t)
{
for(int i=0;i<n;i++)
{
    t[n-1][i]=i+1;
}


for(int i=n-2;i>=0;i--)
{
    for(int j=0;j<n;j++)
    {
        if(j>0 && j<n){t[i][j]=t[i+1][j]+t[i+1][j-1]+t[i+1][j+1];}
        if(j==0) {t[i][j]=t[i+1][j]+t[i+1][j+1];}
        if(j==n-1) {t[i][j]=t[i+1][j]+t[i+1][j-1];}

        if(i<j) {t[i][j]=0;}

    }
}
}

void kiir(int n,int**t)
{
        for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%i ",t[i][j]);
        }
        printf("\n");
    }
}
