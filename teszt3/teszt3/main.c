#include <stdio.h>
#include <stdlib.h>

void feltolt(int *,int);
void kiir(int*,int);

int main()
{
//változók deklarálása
int *t;
int n,i;
printf("Adja meg a tömb méretét!\n");
scanf("%i",&n);

//dinamikus helyfoglalás
t = (int*)calloc(n,sizeof(int));

//tomb elemszámának a beolvasása billentyûzetrõl
for(i=0;i<n;i++)
{
scanf("%i",&t[i]);
}

feltolt(t,n);//véletlenszerûen (rand())
printf(&quot;\nRendezes elott\n&quot;);
kiir(t,n);
printf(&quot;\n&quot;);
}
void feltolt(int *t, int n)
{
    for(int i=0;i<n;i++)
        t[i] = rand()%100+1;
}

void kiir(int *t,int n)
{
for(int i=0;i<n;i++)
{
print("%i",t[i]);
}
}
