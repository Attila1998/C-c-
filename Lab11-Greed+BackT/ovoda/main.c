#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void feltolt(FILE*,int, char**);
void kiir(int,int*,char**);
bool igeretes(int *a,int k,char** nev);
void btk(int* a,int n, int m,int k,char** nev);
int main()
{
    int n,m;
    int* a = (int*)calloc(m,sizeof(int));
    FILE* fin = fopen("nevsor.txt","rt");
    if(!fin)
    {
        printf("Hiba 1");
        return 0;
    }
    fscanf("%i%i",&n,&m);
    printf("%i %i\n",n,m);
    char** nev = (char**)calloc(m,sizeof(char*));
    for(int i = 0 ; i <  m ; i ++)
    {
        nev[i] = (char*)calloc(30,sizeof(char));
    }
    if(!nev)
    {
        printf("Hiba2");
        return 0;
    }
    feltolt(fin,m,nev);
    kiir(m,a,nev);
    return 0;
}

void feltolt(FILE* fin,int m,char** nev)
{
    for(int i = 0 ; i < m ; i++)
    {
        fscanf(fin,"%[^\n]\n",nev[i]);
    }
}

void kiir(int m ,int* a,char** nev)
{
    for(int i = 0 ; i < m ; i++)
    {
        printf("%s \n",nev[a[i]]);
    }
}


void btk(int* a,int n, int m,int k,char** nev)
{
    for(a[k]=1; a[k]<=m; a[k]++)
    {
        if(igeretes(a,m,nev))
        {
            if (k<=n)
            {
                btk(a,n,m,k+1,nev);
            }
            else
            {
                kiir(m,a,nev);
            }
        }
    }
}

bool igeretes(int *a,int k,char** nev)
{
    for(int i=1; i <= k; i++)
    {
        if(a[k]==a[i])
            return false;
    }
    return true;
}
