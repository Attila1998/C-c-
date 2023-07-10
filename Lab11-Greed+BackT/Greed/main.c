#include <stdio.h>
#include <stdlib.h>

typedef struct{
char nev[20];
char knev[20];
int kido;
}Beteg;

int cmp(const void*,const void*);

int main()
{ int n,i;
Beteg *b;
 ///beolvasas
 FILE *fin;
 fin=fopen("beteg.txt","rt");
 fscanf(fin,"%i",&n);
 printf("%i \n",n);
 b=(Beteg*)malloc(n*sizeof(Beteg));

 for(i=0;i<n;i++)
 {fscanf(fin,"%s %s %i", b[i].nev,b[i].knev,&b[i].kido);}

 for(i=0;i<n;i++)
    {printf("%s %s %i \n",b[i].nev,b[i].knev,b[i].kido);}
 /// rendezes
qsort(b,n,sizeof(Beteg),cmp);
 ///Greedy
 printf("\n Greddy: \n");
 int ora=8,perc=0;
 for(i=0;i<n;i++)
 {
     printf("%s %s ora %i  perc %i \n", b[i].nev,b[i].knev,ora,perc);
     perc=perc+b[i].kido;
     ora=ora+perc/60;
     perc=perc%60;
 }
 free(b);
 fclose(fin);
 return 0;
}

int cmp(const void *p1,const void *p2)
{
    Beteg *q1=(Beteg*)p1;
    Beteg *q2=(Beteg*)p2;
    return (q1->kido-q2->kido);
}
