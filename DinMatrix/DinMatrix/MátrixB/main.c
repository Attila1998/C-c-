#include <stdio.h>
#include <stdlib.h>

void kiir(int ,int**);
void nemtudommi(int,int**);

int main()
{

int n,i,j;
FILE* fin = fopen("Matrix.txtx","rt");
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
nemtudommi(int n, int** t);

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

void nemtudommi(int n,int** t)
{

    int m1=0,m2=0
    for(int i=0;i<n;i++)
        for(j=0;j<n;j++)
    {
           if(i==j) int fe=a[i][j];

            if(i>j && a[i][j]<fe)
            {
                m1=1;
            }

            if(j>i && a[i][j]>fe)
            {
                m2=1;
            }

            if(m1 == 1 && m2 == 1)
            {
                printf("Igen!\n");
            }
            else{printf("Nem!\n");}

    }

}
