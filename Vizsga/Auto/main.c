#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    char tipus[50];
    char szim[50];
    int ev;

}Auto;

int cmp(const void *p1,const void *p2);

int main()
{
    int n,i;
   FILE* fin = fopen("auto.txt","rt");
   if(!fin){printf("Hiba nr 1!");return 0;}
   /// be olvassuk az elemszamot egy n változóba
   fscanf(fin,"%i",&n);
   printf("A listaban levo elemek szama: %i \n",n);
    /// létrehozunk egy strukt típusu dinamikus tömböt ami az elején 0-al van tele a calloc miatt
    Auto *a;
    a = (Auto*)calloc(n,sizeof(Auto));
    if(!a){printf("Hiba nr 2!");return 0;}
    ///be olvassuk a tömb elemeit majd ki is íratjuk ezeket
    for(i = 0; i < n ; i++)
    {
        fscanf(fin,"%s%s%i",&a[i].tipus,&a[i].szim,&a[i].ev);
    }

        for(i = 0; i < n ; i++)
    {
        printf("%s %s %i \n",a[i].tipus,a[i].szim,a[i].ev);
    }

printf("\n");
printf("Rendezes utani tomb\n");

///Rendezés
qsort(a,n,sizeof(Auto),cmp);
        for(i = 0; i <n ; i++)
    {
        printf("%s %s %i \n",a[i].tipus,a[i].szim,a[i].ev);
    }

///Legfiatalabb Autó
printf("\n");
printf("Legfiatalabb Auto: \n");
//printf("%s %s %i \n",a[n-1].tipus,a[n-1].szim,a[n-1].ev);
int lf = 100,curent = 2021,save;
for(i = n ; i >=0 ; i--)
{
    if(curent-a[i].ev < lf)
        save=a[i].ev;
}
for(i = 0 ; i < n ; i ++)
{
    if(save == a[i].ev)
        printf("%s %s %i \n",a[i].tipus,a[i].szim,a[i].ev);
}
///Legidõsebb Autó
printf("\n");
printf("Legidosebb Auto: \n");
int li = 0;
for(i = 0 ; i <n ; i++)
{
    if(curent-a[i].ev > li)
        save=a[i].ev;
}
for(i = 0 ; i < n ; i ++)
{
    if(save == a[i].ev)
        printf("%s %s %i \n",a[i].tipus,a[i].szim,a[i].ev);
}

    fclose(fin);
    free(a);
    return 0;
}

int cmp(const void *p1,const void *p2)
{
    Auto *q1 = (Auto*) p1;
    Auto *q2 = (Auto*) p2;
    return (q2->ev - q1->ev);
    /*if (q1->ev < q2->ev) {return -1;}
    else if (q1->ev < q2->ev) {return 1;}
    else return 0;*/
}
