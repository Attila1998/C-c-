#include <stdio.h>
#include <stdlib.h>

void kiir(int ,int**);
int nemtudommi(int,int**);

int main()
{

int n,i,j;
FILE* fin = fopen("Matrix.txt","rt");
if(!fin){printf("Hiba!");return 0;}
fscanf(fin,"%i",&n);
printf("n erteke:%i \n",n);
int**t;
*t=(int**)calloc(n,sizeof(int));
t=(int*)calloc(n,sizeof(int));
for(i=0;i<n;i++)
    for(j=0;j<n;j++)
{
    fscanf(fin,"%i",&t[i][j]);
}

kiir(n,t);
int m=nemtudommi(int n, int** t);
printf("vegeredmeny: %i",m);


return 0;
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

int nemtudommi(int n,int** t)
{
    int max,save,osszeg=0;
    for (int i=n;i>0;i--)
        max = 0;
        for(j=n;j>0;j--)
    {
        if(t[i][j]>max && save)
        {
            max=t[i][j];
            save=max;
            osszeg+=max;
        }
    }
    return max;
}
