#include <stdio.h>
#include <stdlib.h>

typedef struct Varos
{
    char nev[3];
    char ido[6];
    char szoveg[6];
    int homerseklet;
} Varos;

int main()
{
    int n,i;
    FILE* fin = fopen("tavirathu13.txt","rt");
    if(!fin)
    {
        printf("Beolvasas Hiba!\n");
        return 0;
    }

    fscanf(fin,"%i",&n);
    Varos *t = (Varos*)calloc(n,sizeof(Varos));
    for( i=0; i<n; i++)
    {
        fscanf(fin,"%s %s %s %i",&t[i].nev,&t[i].ido,&t[i].szoveg,&t[i].homerseklet);
    }


    for( i=0; i<n; i++)
    {
        printf("%s  %s  %s  %i\n",t[i].nev,t[i].ido,t[i].szoveg,t[i].homerseklet);
    }
    printf("\n \n");

    printf("Kerem adja meg egy varps kodjat:\n");

    char kod[3];
    char legregebbiIdo[6];
    scanf("%s",&kod);

    for(i=0;i<n;i++)
    {
        if(strcmp(t[i].nev,kod) == 0)
        {
            //printf(" %s\n",t[i].ido);
            strcpy(legregebbiIdo,t[i].ido);
        }
    }
    printf("\n\n\n Legkesobbi meres: %s \n\n\n",legregebbiIdo);

int min=40,max=0,minIndex=0,maxIndex=0;

for(i=0;i<n;i++)
{
    if(t[i].homerseklet >= max )
    {
        max = t[i].homerseklet;
        maxIndex = i;
    }
    if (t[i].homerseklet <= min)
    {
        min = t[i].homerseklet;
        minIndex = i;
    }
}

for(i=0;i<n;i++)
{
    if( i == maxIndex)
    {
        printf("Legnagyobb mert hmerseklet: %s  %s  %i\n",t[i].nev,t[i].ido,t[i].homerseklet);
    }
}

for(i=0;i<n;i++)
{
    if( i == minIndex)
    {
        printf("Legkisebb mert hmerseklet:%s  %s  %i\n",t[i].nev,t[i].ido,t[i].homerseklet);
    }
}

bool szel = false;
for(i=0;i<n;i++)
{
    if(strcmp(t[i].szoveg,"00000") == 0)
    {
        printf("Szelcsendes volt: %s  %s \n",t[i].nev,t[i].ido);
        szel = true;
    }
}

if (szel == false)
{
printf("Nem volt szelcsendes hely!\n");
}

free (t);
fclose(fin);
    return 0;
}
