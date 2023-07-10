#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct tanulo
{
    char nev[10];
    char nyelv[10];
} tanulo;


int main()
{
    FILE *fin = fopen("be.txt", "rt");
    int n,m;
    tanulo *t;
    fscanf(fin,"%i",&n);

    char ** nyelvek=(char **)malloc(n*sizeof(char*));

    for(int i=0; i<n; ++i)
    {
        nyelvek[i]=(char *)malloc(1*sizeof(char));
        fscanf(fin,"%s",nyelvek[i]);

    }

    fscanf(fin,"%i",&m);
    t=(tanulo*)malloc(m*sizeof(tanulo));
    for(int i=0; i<m; ++i)
    {
        fscanf(fin,"%s%s",t[i].nev,t[i].nyelv);
    }
    int x;
    printf(" illegalis nyelv hasznalok: ");
    for(int i=0; i<m; ++i)
    {
        x=0;
        for(int j=0; j<n; ++j)
        {
            if(strcmp(t[i].nyelv,nyelvek[j])!=0)
            {
                ++x;
            }
        }
        if(x==n)
        {
            printf("%s",t[i].nev) ;
            printf("\n");
        }
    }
    printf(" nem valasztott nyelv: ");
    int f;
    for(int i=0; i<n; ++i)
    {
        f=0;
        for(int j=0; j<m; ++j)
        {
            if(strcmp(nyelvek[i],t[j].nyelv)!=0)
            {
                ++f;
            }
        }
        if(f==m)
        {
            printf("%s",nyelvek[i]) ;
            printf("\n");
        }
    }
     printf("a nyelvek valasztasanak szama: ");
     int q;
        for(int i=0; i<n; ++i)
    {
        q=0;
        for(int j=0; j<m; ++j)
        {
            if(strcmp(nyelvek[i],t[j].nyelv)==0)
            {
                ++q;
            }
        }
     printf("%s:%i\n",nyelvek[i],f);
    }
 return 0;
}
