#include <stdio.h>
#include <stdlib.h>
int beolvasas(int n, int *t, FILE fin,int i);
void kiiras(int n,int *t,int i);
int mini(int *t[],int i);
int maxi(int *t[],int i);

int main()
{
    int i=1,*t,n;
    FILE *fin;
    fin=fopen("tomb.txt","rt");
    if(!fin)
        {
        printf("Hiba a szoveges allomany megnyitasaban!");
        return 0;
         }
    else{fscanf(fin,"%i ",&n);}
    t=(int*)calloc(n,sizeof(int));
    beolvasas(n,*t,*fin,i);
    //kiiras(int n,FILE *t,int i);
    return 0;
}


int beolvasas(int n, int *a, FILE fin,int i)
{
    if(fscanf(fin,"%i",&a[i])!=EOF){
        printf("%i ", a[i]);
        beolvasrek(a,n,fin,i+1);
    }
}
   /* void kiiras(int n,int *t,int i)
    {
    if(n==i)
    {printf("%d ",t[i]);}
    else{kiiras(n,*t,i+1);}
    }
*/
int maxi(int *a[],int i)
{
    if(i==0){return i;}
    else{
        int m1=maxi(a,i);
        int m2=maxi(a,i+1);
        if(a[m1]>a[m2])
        {return m1;}
        else
         {return m2;}
        }
    }



int mini(int *a[],int i)
{
    if(i==0){return i;}
    else{
        int m1=mini(a,i);
        int m2=mini(a,i+1);
        if(a[m1]<a[m2])
        {return m1;}
        else
         {return m2;}
        }
    }
