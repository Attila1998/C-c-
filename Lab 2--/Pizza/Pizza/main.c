#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char pizzanev[20];
    char hozzavalok[50];
    int ar;
} pizza;

int main()
{
    int i,n;
    pizza *t;
    FILE *fin,*bin;
    fin=fopen("pizza.txt","rt");
    bin=fopen("pizza.dat","wb");
    if(!fin)
    {
        printf("Hiba!");
        return 0;
    }
    fscanf(fin, "%i", &n);
    t=(pizza*)malloc(n*sizeof(pizza));
    for( i = 0 ; i < n ; ++i)
    {
        fscanf(fin, "%s %s %i", &t[i].pizzanev,&t[i].hozzavalok,&t[i].ar);
    }
    fwrite(t,sizeof(pizza),n,bin);
    ///fprint(fout,a[i],n,t)
    free(t);
    fclose(fin);
    fclose(bin);

 /*  bin=fopen("pizza.dat","rb");
    t=(pizza*)malloc(n*sizeof(pizza));
    fread(t,sizeof(pizza),n,bin);

    printf("pizzak: \n");
    for( i = 0 ; i < n ; ++i)
    {
        printf("%s %s %i \n", t[i].pizzanev,t[i].hozzavalok,t[i].ar);
    }

    free(t);
    fclose(bin);
*/

}
