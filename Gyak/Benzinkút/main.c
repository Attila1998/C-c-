#include <stdio.h>
#include <stdlib.h>

int main()
{
   int N=0,K=0,*t;
   FILE* fin=fopen("Bemenet.txt","rt");
   if(!fin)
    {
        printf("ERROR!");
        return 0;
    }
   fscanf(fin,"%i",&N);
   printf("N: %i \n",N);
   fscanf(fin,"%i",&K);
   printf("K: %i \n",K);
   t=(int*)calloc(N,sizeof(int));
   for(int i=0;i<N;i++){
    fscanf(fin,"%i",&t[i]);
   }
    for(int i=0;i<N;i++){
    printf("%i,",t[i]);
   }
int i=0,k=1;
printf("\nMegallok: 1\n");
while (i<N)
{
    int ossz=0;
    while(1)
    {
        //printf("%i-edik megallo osszege: %i\n",i+1,ossz);
        ossz=ossz+t[i];
        if(ossz>K){printf("Megallok: %i\n",i+1);ossz=t[i];k++;}

    i++;
    if(i>N){break;}
    }
}

printf("Megallok szama:%i",k);


    return 0;
    free(t);
    fclose(fin);
}
