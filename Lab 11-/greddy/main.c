#include <stdio.h>
#include <stdlib.h>
int int_cmp(const void*, const void*);
int main()
{ int n,i,osszeg=277,*a;
 //beolvasas
 FILE *fin=fopen("penzek.txt","rt");
 fscanf(fin,"%i ",&n);
 printf("%i ",n);
 printf("\n");
 a=(int*)malloc(n*sizeof(int));
 for(i=0;i<n;i++)
 {
     fscanf(fin,"%i ",&a[i]);
 }

  for(i=0;i<n;i++)
 {
     printf("%i ,",a[i]);
 }
 printf("\n");
 //rendezes-csokkenobe(qsort)
qsort(a,n,sizeof(int),int_cmp);
printf("\nRendezett: \n");
  for(i=0;i<n;i++)
 {
     printf("%i ",a[i]);
 }
 printf("\n");
 //Greedy
int db;
for(i=0;i<n && osszeg>=0;i++)
{
    db=0;
    if(a[i]<=osszeg)
    {
    db=osszeg/a[i];
    osszeg=osszeg%a[i];
    printf("\n %i x %i ;",db,a[i]);
    //printf("%i",a[i]);
    }
}
if(osszeg!=0){printf("Hiba!");}
return 0;
}

int int_cmp(const void *p1,const void *p2)
{
    int *q1=(int*)p1;
    int *q2=(int*)p2;
    if(*q1>*q2){return -1;}
    else if(*q1<*q2){return 1;}
    else{return 0;}
}
