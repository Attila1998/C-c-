#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int sz_ossz(int n);
int sz_szor(int n);
int sz_szam(int n);
int sz_kicsi(int n);
int sz_nagy(int n);
bool prim(int n,int i);
int Lnko(int a, int b);
long Lkkt(long a, long b);

int main()
{
    int n;
    printf("Kerek egy szamot: \n");
    scanf("%i",&n);
    printf("Szamjegyeinek Osszege: %i ", sz_ossz(n));
    printf("\n");
    printf("Szamjegyeinek szorzata: %i ", sz_szor(n));
    printf("\n");
    printf("Szamjegyeinek szama: %i ", sz_szam(n));
    printf("\n");
    printf("Legkisebb szamajegy: %i ", sz_kicsi(n));
    printf("\n");
    printf("Legnagyobb szamajegy: %i ", sz_nagy(n));
    printf("Prime: %i",prim(n,6));
    int a,b;
    printf("Kerek ket szamot: \n");
    printf("Lnko: %i ", Lnko(a,b));
    printf("\n");
    printf("Lkkt: %i ", Lkkt(a,b));
    return 0;
}

int sz_ossz(int n)
{
    int a=0;
    if(n==0)
    {
        return 0;
    }
    else
    {
        a=sz_ossz(n/10);
        return a+n%10;
    }
}

int sz_szor(int n)
{
    int a=1;
    if(n==0)
    {
        return 1;
    }
    else
    {
        a=sz_szor(n/10);
        return a*(n%10);
    }
}

int sz_szam(int n)
{
    if (n<10)
    {
        return 1;
    }
    else
    {
        return 1+sz_szam(n/10);
    }
}

int sz_kicsi(int n)
{
    if(n<10)
    {
        return n;
    }
    else
    {
        int mini=sz_kicsi(n/10);
        if( mini < n%10 )
        {
            return mini;
        }
        else
        {
            return n%10;
        }
    }
}

int sz_nagy(int n)
{
    if(n<10)
    {
        return n;
    }
    else
    {
        int maxi=sz_nagy(n/10);
        if( maxi > n%10 )
        {
            return maxi;
        }
        else
        {
            return n%10;
        }
    }
}
bool prim(int n,int i)
{
    if(i==1)
    {
        return true;
    }
    else
    {
        if(n%i==0)
        {
            return false;
        }
        else
        {
            prim(n,i-1);
        }
    }
}

int Lnko(int a, int b)
{

    if (a == b)
    {
        return a;
    }
    else if (a > b)

        {return Lnko(a - b, b);}
    else
        {return Lnko(a, b - a);}


}

long Lkkt(long a, long b)
{
return a * b / Lnko(a, b);
}
