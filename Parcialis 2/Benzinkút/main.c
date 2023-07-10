#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,K,*t;
    FILE* fin=fopen("Tavolsag.txt","rt");
    if(!fin)
    {
        printf("ERROR!");
        return 0;
    }
    fscanf(fin,"%i %i",&N,&K);
    printf("N: %i \nK: %i \n",N,K);
    t=(int*)malloc(N*sizeof(int));
    for(int i=0; i<N; i++)
    {
        fscanf(fin,"%i",&t[i]);
    }

    for(int i=0; i<N; i++)
    {
        printf("%i ;",t[i]);
    }
    printf("\n");
//Greedy

   /* printf("Megallok: ");
    int Tsz=0;
    for(int i=0; i<N-1; i++)
    {
    int ossz=0;
    ossz=ossz+t[i];
    if(ossz>K)
    {
        printf("Megallok: %i\n",i+1);
        ossz=t[i];
    }
    }

    printf("\nTankolasok szama: %i", Tsz);*/



    int i=0;
    //printf("Megallok: 1 \n");
    printf("Megallok: 1;");
    while(i<N)
    {
        int ossz=0;
    int Tsz=0;

        while(1)
        {
           //printf("%i -edik megallo osszege: %i\n", i+1, ossz);
            ossz=ossz+t[i];
            if(ossz>K)
            {
                printf("%i;", i+1);
                ossz=t[i];
                Tsz++;
            }
            i++;
            if(i==N)
            {
                break;
            }



        }
printf("\nMegallok szama: %i",Tsz+1);
    }


    return 0;
}
