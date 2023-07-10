#include <stdio.h>
#include <stdlib.h>

typedef struct Adat
{
    int hely1;
    int hely2;
    char vezeteknev[50];
    char nev[50];
    char korszag[50];
    char szuletesih[50];
    int eletkor;

} Adat;

void feltoltes(FILE* fin,int n,Adat* t);
void kiir(int n,Adat* t);
void francia(int n,Adat* t);

int main()
{
    int n;
    FILE* fin = fopen("focistak.txt","rt");
    if(!fin)
    {
        printf("Hiba1!\n");
        return 0;
    }
    fscanf(fin,"%i",&n);
    printf("%i",n);
    Adat* t;
    t = (Adat*)calloc(n,sizeof(Adat));
    if(t == NULL)
    {
        printf("Hiba2!\n");
        return 0;
    }

    feltoltes(fin,n,t);
    kiir(n,t);
    francia(n,t);

    return 0;
}

void feltoltes(FILE* fin,int n,Adat* t)
{
    int i;
    for(i =0; i<n; i++)
    {
        fscanf(fin,"%i%i%s%s%s%s%i",&t[i].hely1,&t[i].hely2,&t[i].vezeteknev,&t[i].nev,&t[i].korszag,&t[i].szuletesih,&t[i].eletkor);
    }
}

void kiir(int n,Adat* t)
{
    int i;
    for(i =0; i<n; i++)
    {
        fprintf("%i,%i,%s,%s,%s,%s,%i",t[i].hely1,t[i].hely2,t[i].vezeteknev,t[i].nev,t[i].korszag,t[i].szuletesih,t[i].eletkor);
    }
}

void francia(int n,Adat* t)
{
    char x = "Franciaország";
    int temp = 0;
    int i;
    for(i=0; i<n; i++)
        if(strcmp(t[i].szuletesih,x))
        {
            temp += 1;
        }
    printf("Franciaorszagban szuletettek szama: %i",temp);
}
