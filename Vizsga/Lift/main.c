#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    char nev[50];
    int nem;
    int ev;
    int emelet;

}Szemely;

int cmp(const void *p1,const void *p2);///kor szerint csokkeno sorrend
int cmp2(const void *p1,const void *p2);///emelet szerint novekvo
int cmp3(const void *p1,const void *p2);///nem szerint, nok elol
int main()
{
    int n,i;
   FILE* fin = fopen("tombhaz.txt","rt");
   if(!fin){printf("Hiba nr 1!");return 0;}
   /// be olvassuk az elemszamot egy n változóba
   fscanf(fin,"%i",&n);
   printf("A listaban levo elemek szama: %i \n",n);
    /// létrehozunk egy strukt típusu dinamikus tömböt ami az elején 0-al van tele a calloc miatt
    Szemely *a;
    a = (Szemely*)calloc(n,sizeof(Szemely));
    if(!a){printf("Hiba nr 2!");return 0;}
    ///be olvassuk a tömb elemeit majd ki is íratjuk ezeket
    for(i = 0; i < n ; i++)
    {
        fscanf(fin,"%s%i%i%i",&a[i].nev,&a[i].nem,&a[i].ev,&a[i].emelet);
    }
    printf("\n");
        for(i = 0; i < n ; i++)
    {
        printf("%s %i %i %i\n",a[i].nev,a[i].nem,a[i].ev,a[i].emelet);
    }

printf("\n");
///Kor szereint csokkeno
printf("\n");
qsort(a,n,sizeof(Szemely),cmp);
printf("Rendezett tomb kor szerint:\n");
for(i = 0; i < n ; i++)
{
    printf("%s %i %i %i\n",a[i].nev,a[i].nem,a[i].ev,a[i].emelet);
}

int ido1=0;
for(i = 0; i < n ; i++)
{
   ido1 =((1+a[i].emelet)*2);
   printf("ido: %i\n",ido1);
}
printf("ido: %i\n",ido1);

///Emelet szerint
printf("\n");
qsort(a,n,sizeof(Szemely),cmp2);
printf("Rendezett tomb: emelet\n");
for(i = 0; i < n ; i++)
{
    printf("%s %i %i %i\n",a[i].nev,a[i].nem,a[i].ev,a[i].emelet);
}

int ido2=0;
for(i = 0; i < n ; i++)
{
   ido2 =ido2 +((1+a[i].emelet)*2);
}
printf("ido: %i\n",ido2);

///Nem szerint
printf("\n");
qsort(a,n,sizeof(Szemely),cmp3);
printf("Rendezett tomb nem szerint:\n");
for(i = 0; i < n ; i++)
{
    printf("%s %i %i %i\n",a[i].nev,a[i].nem,a[i].ev,a[i].emelet);
}

int ido3=0;
for(i = 0; i < n ; i++)
{
   ido3 =ido3 +((1+a[i].emelet)*2);
}
printf("ido: %i\n",ido3);

    fclose(fin);
    free(a);
    return 0;
}

int cmp(const void *p1,const void *p2)
{
    Szemely *q1 = (Szemely*) p1;
    Szemely *q2 = (Szemely*) p2;
    return (q2->ev - q1->ev);
}

int cmp2(const void *p1,const void *p2)
{
    Szemely *q1 = (Szemely*) p1;
    Szemely *q2 = (Szemely*) p2;
    return (q1->emelet - q2->emelet);
}

int cmp3(const void *p1,const void *p2)
{
    Szemely *q1 = (Szemely*) p1;
    Szemely *q2 = (Szemely*) p2;
    return (q2->nem - q1->nem);
}
