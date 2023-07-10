///Permutacio
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void kiir(int *x, int n)
{
    int i;
    for(i=1; i<=n; i++)
        printf("%i" ,x[i]);
    printf("\n");
}
bool igeretes(int *x,int n, int k)
{
    int i;
    for(i=1; i<=k-1; i++)
        if(x[k]==x[i])
            return false;
    return true;
}
void back(int *x,int n,int k)
{
    int i;
    for(x[k]=1; x[k]<=n; x[k]++)
        if(igeretes(x,n,k))
            if(k&lt; n)
                back(x,n,k+1);
    elsekiir(x,n);
}
int main()
{
    int n;
    scanf("%i" ,&n);
    int *x=(int*)calloc(n,sizeof(int));
    back(x,n,1);
    return 0;
}
