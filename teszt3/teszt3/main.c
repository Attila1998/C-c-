#include <stdio.h>
#include <stdlib.h>

void feltolt(int *,int);
void kiir(int*,int);

int main()
{
//v�ltoz�k deklar�l�sa
int *t;
int n,i;
printf("Adja meg a t�mb m�ret�t!\n");
scanf("%i",&n);

//dinamikus helyfoglal�s
t = (int*)calloc(n,sizeof(int));

//tomb elemsz�m�nak a beolvas�sa billenty�zetr�l
for(i=0;i<n;i++)
{
scanf("%i",&t[i]);
}

feltolt(t,n);//v�letlenszer�en (rand())
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
