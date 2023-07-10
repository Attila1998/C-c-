#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char Varosnev[25];
    int honap[12];
} VAROS;

int main()
{
    int n,i,j,s[20];

    FILE*fin=fopen("Ittas_Vezetes.txt","rt");
    fscanf(fin,"%i",&n);
    VAROS* a=(VAROS*)malloc(n*(sizeof(VAROS)));


    printf("%i\n",n);
    for(i=0; i<n; ++i)
    {
        fscanf(fin,"%s" ,&a[i].Varosnev);

        for(j=0; j<12; ++j)
        {
            fscanf(fin,"%i",&a[i].honap[j]);
        }

    }


    for(i=0; i<n; ++i)
    {
        printf("%s " ,a[i].Varosnev);

        for(j=0; j<12; ++j)
        {
            printf("%i ",a[i].honap[j]);
        }
        printf("\n");
    }


    osszes(a,n,s);///varosok evi ittas vezetoinek a szama
    for(i=0; i<n; ++i)
    {
        printf("%i ", s[i]);
    }
    printf("\n%i",s[reszegvaros(s,n)]);/// legtöbb ittas vezetõ varosa


    adott_varos(a,n);///Adott varosra kiirja azt a honapot amelyikben a legtobb ittas vezeto volt

    return 0;
}


void osszes(VAROS *A,int n,int *s)
{
    int i,j,k=0;
    for(i=0; i<n; ++i)
    {
        for(j=0; j<12; ++j)
        {
            k+=A[i].honap[j];
        }
        s[i]=k;
        k=0;

        //printf("%i ",s[i]);
    }
    return s;
}

int reszegvaros(int* s,int n)
{
    int i,max,maxh=0;

    max=s[0];
    for(i=1; i<n; ++i)
    {
        if(s[i]>max)
        {
            max=s[i];
            maxh=i;
        }

    }
    return maxh;
}
void adott_varos(VAROS* A,int n)
{
    char s[25];
    int i,j,x=0,max,maxh=1;

    printf("\nIrj be egy varost ");
    do
    {
        scanf("%s",s);
        for(i=0; i<n; ++i)
        {

            if(strcmp(A[i].Varosnev,s)==0)
            {
                max=A[i].honap[0];
                for(j=1; j<12; j++)
                {

                    if(A[i].honap[j]>max)
                    {
                        maxh=j;
                        max=A[i].honap[j];
                    }
                }
                printf("\n%i ",i);
                x=1;
            }
        }
    }
    while(x!=1);
    printf("\nA(z) %i . honapban volt a legtobb ittas vezeto a varosban" ,maxh+1);
}


