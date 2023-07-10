#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int **f(int n,int m);
int main()
{
int **a,n,m,i,j,k,*c;
srand(time(NULL));
printf("A matrix merete:\n");
scanf("%i",&n);
scanf("%i",&m);
 a=f(n,m);

//kiiras
for(i=0;i<n;i++)
{
    for(j=0;j<m;j++)
    {
        printf("%i ",a[i][j]);
    }
    printf("\n");

}
printf("\n");
printf("statisztika: \n");
c=(int*)calloc(49,sizeof(int));
for(i=0;i<n;i++)
{
    for(j=0;j<m;j++)
    {
      c[a[i][j]]+=1;
    }
}
for(k=0;k<50;k++)
{
    if(c[k]!=0) {printf("%i -> %i; \n",k,c[k]);}
}
return 0;
}


int **f(int n,int m)
{

    int**a,i,j;
    a=(int**)calloc(n,sizeof(int));
    for(i=0;i<n;i++)
{
    a[i]=(int*)calloc(m,sizeof(int));
    for(j=0;j<m;j++)
    {
         a[i][j] = rand() % 50+1;
    }
}
return a;
}
