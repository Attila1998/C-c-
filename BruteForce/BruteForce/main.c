#include <stdio.h>
#include <stdlib.h>

int BF(int,int);///BruteForce;
int AE(int,int);///Divide and Qonquer->allando ertek;
int AF(int,int);///Divide and Qonquer->Adott faktor;

int main()
{
   int x,n;
   printf("Kerek 2 szamot:\n");
scanf("%i",&x);
scanf("%i",&n);

printf("Brute Force: %i\n",BF(x,n));
printf("Allando Ertek: %i\n",AE(x,n));
printf("Adott Faktor: %i\n",Af(x,n));
return 0;
}

int BF(int x,int n)
{
   int p=1;
   for(int i=0;i<n;i++)
        {p*=x;}
   return p;
}

int AE(int x,int n)
{
    if n == 0
    {
        return 1;
    }
    else
    {
        AE( x , n - 1 ) * x;
    }
}

int AF(int x,int n)
{
    int h;
    if(n == 0){return 1;}
    else
    {
        if(n%2 == 0)
        {
            int h = AF(x,n/2);
            return h*h;
        }
        else
        {
            h = AF(x,(n-1)/2);
            return h*h*x;
        }
    }
}
