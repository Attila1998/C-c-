#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nev[20];
    char becenev[10];
    int kor;
}szemely;

int ekor_cmp ( const void *p1, const void *p2 );
int nev_cmp ( const void *p1, const void *p2 )
int main()
{
    int i,n;
    szemely *t;
    FILE *fin;
    fin=fopen("be.txt","rt");
    if(!fin)
    {
        printf("Hiba!");
        return 0;
    }
    fscanf(fin, "%i", &n);
    t=(szemely*)malloc(n*sizeof(szemely));
    for( i = 0 ; i < n ; ++i)
    {
        fscanf(fin, "%s %s %i", &t[i].nev,&t[i].becenev,&t[i].kor);
    }
    printf("szemelyek: \n");
    for( i = 0 ; i < n ; ++i)
    {
        printf("%s %s %i \n", t[i].nev,t[i].becenev,t[i].kor);
    }
    printf("\n");
    qsort ( t, n, sizeof(szemely), ekor_cmp );

        printf("rendezve: \n");
    for( i = 0 ; i < n ; ++i)
    {
        printf("%s %s %i \n", t[i].nev,t[i].becenev,t[i].kor);
    }
    free(t);
    //fclose(be.txt);
    return 0;
}
int nev_cmp ( const void *p1, const void *p2 )
{
   szemely *q1 = (szemely *)p1;
    szemely *q2 = (szemely *)p2;
    return strcmp(q1->nev,q2->nev);
}

int ekor_cmp ( const void *p1, const void *p2 )
{
szemely *q1 = (szemely *)p1;
szemely *q2 = (szemely *)p2;
if ( q1->kor > q2->kor )
    { return -1; }
else
    if ( q1->kor < q2->kor )
    { return 1; }
    else
    { return 0; }
}
