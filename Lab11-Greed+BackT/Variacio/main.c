///Variáció
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void kiir(int *x, int k)
{int i;
for(i=1;i<=k;i++)
printf("%i",x[i]);
printf("/n");
}
bool igeretes(int *x,int n, int k)
{int i;
for(i=1;i<=k-1;i++)
if(x[k]==x[i])
return false;
return true;
}
void back(int *x,int n,int m,int k)
{int i;
for(x[k]=1;x[k]<=n; x[k]++)
if(igeretes(x,n,k))
if(k<m)
back(x,n,m,k+1);
else
kiir(x,k);
}
int main()
{int n,m;
scanf("%i %i",&n,&m);
int *x=(int*)calloc(n,sizeof(int));
back(x,n,m,1);
return 0;
}
