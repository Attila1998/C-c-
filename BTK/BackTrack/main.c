#include <stdio.h>
#include <stdlib.h>

bool igeretes(int *a,int k,char flag[10][10]);
void btk(int n, int*a,int k,char flag[10][10]);

int main()
{
    FILE* fin = fopen("szinek.txt","rt");
    if(!fin)
    {
        printf("Hiba!");
        return 0;
    }

    int n ;
    fscanf(fin,"%i",&n);
    printf(" Szinek  szama: %i\n",n);
    int k = n/2;
    int *a = (int*)calloc(n,sizeof(int));
    char** flag;
    flag = (char**)calloc(n,sizeof(char*));
    for(int i = 0 ; i < n ; i ++)
    {
        flag[i] = (char*)calloc(n,sizeof(char));
    }
    if(!flag)
    {
        printf("Hiba2!");
        return 0;
    }

    for(int i=1; i<=n; i++)
    {
        fscanf(fin,"%s",flag[i]);
    }

    btk(n,a,3,flag);


fclose(fin);
free(flag);
free(a);
    return 0;
}

bool igeretes(int *a,int k,char flag[10][10])
{
    for(int i=1; i&lt; k; i++)
        if(a[k]==a[i])
            return false;
    if(k==2 && strcmp(flag[a[k]],"piros")!=0)
        return false;
    return true;
}

void btk(int n, int*a,int k,char flag[10][10])
{
    for(a[k]=1; a[k]<=n; a[k]++)
    {
        if(igeretes(a,k,flag))
        {
            if (k&lt; 3)
            {
                btk(n,a,k+1,flag);
            }
            else
            {
                kiir(a,k,flag);
            }
        }
    }
}

///ez ìgy szar xD

void kiir(int *a, int k,char flag[10][10])
{
for(int i=1;i&lt;=k;i++)
{printf("%s",a[i]);}
printf("\n");
}
