#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Nev
{
    char nev[20];
} Nev;
Nev *Nevek;
int main()
{
    int m;
    FILE *file;
    FILE *fin=fopen("nevsor.txt", "rt");
    if(!fin)
    {
        printf("Error 404!\n");
    }
    fscanf(fin, "%i", &m);
    int *t;

    t=(int*)malloc((m)*sizeof(int));
    Nevek=(Nev*)malloc((m+1)*sizeof(Nev));

    printf(" A listaban talalt elemek szama: %i\n\n", m);
    for (int i=1; i<=m; i++)
    {
        fscanf(fin, "%s", Nevek[i].nev);
        //printf("Csinald\n");
        printf(" %s ", Nevek[i].nev);
    }

   // nevpermutacio(file,t,m,elemszam,1);
}

bool igeretes(int *t, int k)
{
    for(int i=1; i<=k-1; i++)
    {
        if(t[i]==t[k] )
        {

            return false;

        }
    }
    return true;
}

void nevpermutacio(FILE *file, int *t, int n, int h, int k)
{
    for(t[k]=1; t[k]<=n; t[k]++)
    {


        if(igeretes(t,k))
        {

            if(k<h)
            {
                nevpermutacio(file,t,n, h,k+1);
            }
            else
            {
                kiir(file,t,n, h);
            }
        }


            if(varteszt(t,k))
            {

                if(k<h)
                {
                    nevpermutacio(file,t,n, h,k+1);
                }
                else
                {
                    kiir(file,t,n, h);
                }
            }


    }
}

void kiir(FILE *file, int *t, int n, int h)
{
    for(int i=1; i<=h; i++)
    {

        fprintf(file,"%s ",nevek[t[i]].nev);
        printf("%s ",Nevek[t[i]].nev);
    }
    fprintf(file, "\n");
    printf( "\n");

}
bool varteszt(int *t, int k)
{
    for(int i=1; i<=k-1; i++)
    {
        if(t[i]<t[k])
        {

            return false;

        }
    }
    return true;
}

