///Részhalmaz
#include <stdio.h>
#include <stdlib.h>
void kiir(int *x, int n)
{
    int i;
    for(i=1; i<=n; i++)
        printf(" %i "; ,x[i]);
    printf(" \n");
}
void back(int *x,int n,int k)
{
    int i;
    for(x[k]=0; x[k]< =1; x[k]++)
        if(k < n)
            back(x,n,k+1);
        else
            kiir(x,n);
}
int main()
{
    int n;
    scanf("%i", &n);
    int *x=(int*)calloc(n,sizeof(int));
    back(x,n,1);
    return 0;
}
