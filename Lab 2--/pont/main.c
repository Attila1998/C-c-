#include <stdio.h>
#include <stdlib.h>

typedef struct{
int x;
int y;
}pont;
int main()
{
    int i,n;
    pont *t;
    FILE *fin;
    fin=fopen("pont.txt","rt");
    if(!fin)
    {
        printf("Hiba!");
        return 0;
    }
    fscanf(fin, "%i", &n);
    t=(pont*)malloc(n*sizeof(pont));
    for( i = 0 ; i < n ; ++i)
    {
        fscanf(fin, "%i %i",&t[i].x,&t[i].y);
    }

    printf("pontok: \n");
    for( i = 0 ; i < n ; ++i)
    {
        printf("%i %i \n", t[i].x,t[i].y);
    }


    return 0;
}
