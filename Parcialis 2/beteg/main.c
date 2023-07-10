#include <stdio.h>
#include <stdlib.h>

int main()
{
int n,i,*t;
FILE* fin=fopen("beteg.txt","rt");
if(!fin){printf("Error!");return 0;}

fscanf(fin,"%i ",&n);
printf("%i ",n);
t=(int*)malloc(n*sizeof(int));
for(i=0;i<n;i++)
{
fscanf(fin,"%i ",&t[i]);
}
for(i=0;i<n;i++)
{
    printf("%i ",t[i]);
}

 printf("\n Greddy: \n");
 int perc=0;
 for(i=0;i<n;i++)
 {
     printf("sorrend: %i perc: %i \n",i,perc);
     perc=perc+t[i];
     perc=perc%60;
 }


return 0;
}
