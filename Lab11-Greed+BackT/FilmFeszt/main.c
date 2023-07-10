#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nev[50];
    int kezdes;
    int vege;
} Film;

int cmp(const void*,const void*);

int main()
{
    int n,i;
    Film *f;
///beolvasas

    FILE *fin;
    fin=fopen("program.txt","rt");
    fscanf(fin,"%i\n",&n);
    printf("%i \n",n);
    f=(Film*)calloc(n,sizeof(Film));

    for(i=0; i<n; i++)
    {
        fscanf(fin,"%[^\n]\n%i%i\n", f[i].nev,&f[i].kezdes,&f[i].vege);
    }

    for(i=0; i<n; i++)
    {
        printf("%s \n %i %i \n",f[i].nev,f[i].kezdes,f[i].vege);
    }
    printf("\n");
/// intervallum rendezese
    qsort(f,n,sizeof(Film),cmp);
    /* for(i=0; i<n; i++)
     {
         printf("%s \n %i %i \n",f[i].nev,f[i].kezdes,f[i].vege);
     }*/
///Greedy
    printf("\n Greddy: \n");
    printf("%s \n %i %i \n",f[0].nev,f[0].kezdes,f[0].vege);
    int megnezve = 0;
    for(i=1; i<n; i++)
    {
        if(f[i].kezdes >= f[megnezve].vege)
        {
            printf("%s \n %i %i \n",f[i].nev,f[i].kezdes,f[i].vege);
            megnezve = i;
        }
    }

    fclose(fin);
    free(f);
    return 0;
}

int cmp(const void *p1,const void *p2)
{
    Film *q1=(Film*)p1;
    Film *q2=(Film*)p2;
    return (q1->kezdes - q2->kezdes);
}
