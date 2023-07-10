#include <stdio.h>
#include <stdlib.h>
typedef struct{
    char Vnev[20];
    char Knev[20];
    char Tantargy[15];
    char Osztaly[4];
    int Ora;
}Tanar;
int compareVnev(const void * a, const void * b);
void Osszes(Tanar *t,int n,int *s);




int main()
{
int n,i,j,s[20];
FILE* fin=fopen("Tanar.txt","rt");
fscanf(fin,"%i ",&n);
printf("%i\n",n);
Tanar *t=(Tanar*)malloc(n*sizeof(Tanar));

//Beolvasas:
for(i=0;i<n;i++)
{fscanf(fin,"%s %s %s %s %i",&t[i].Vnev,&t[i].Knev,&t[i].Tantargy,&t[i].Osztaly,&t[i].Ora);}

//Kiiras:
for(i=0;i<n;i++)
{printf("%s %s %s %s %i",&t[i].Vnev,&t[i].Knev,&t[i].Tantargy,&t[i].Osztaly,&t[i].Ora);}

//Csookeno sorrend-Qsort
qsort(t[i].Vnev,n,sizeof(char*),compareVnev);

//Ossza tanitasi ora
Osszes(t,n,s);
for(i=0;i<n;i++)
{
    printf("%i ",s[i]);
}

//Hany oraban tanit
//Tanar_Kereso(a,n);

free(t);
return 0;
}

int compareVnev(const void * a, const void * b)
{
const char*A=(const char*)a;
const char*B=(const char*)b;
  return  strcmp(A,B);
}

void Osszes(Tanar *t,int n,int *s)
{
    int i,j,k=0;
    for(i=0; i<n; ++i)
    {
        for(j=0; j<12; ++j)
        {
            k+=t[i].Ora;
        }
        s[i]=k;
        k=0;
    }
}

void Tanar_kereso(Tanar* t,int n)
{
    char Vnev1[20];
    char Knev1[20];
    int i,j,x=0;

    printf("\nIrj be a tanar nevet ");
}
