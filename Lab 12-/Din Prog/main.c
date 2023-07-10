#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;
    FILE *fin;
    fin=fopen("be.txt", "rt");
    if(!fin)
    {
        printf("Error!");
        return 0;
    }
    fscanf(fin, "%i %i ", &n,&m);
    printf("Matrix meret:%i;%i \n\n",n,m);
    int **a, **c;
    a=(int**)calloc(n+1, sizeof(int *));
    c=(int**)calloc(n+1, sizeof(int *));
    for(int i=0; i<n+1; i++)
    {
        a[i]=(int *)calloc(m+1, sizeof(int));
        c[i]=(int*)calloc(m+1, sizeof(int ));
    }
    printf("Matrix: \n");
    for(int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            fscanf(fin, "%i", &a[i][j]);
            printf("%i ; ", a[i][j]);
        }
        printf("\n");
    }
    for(int i=1; i<=n; i++)
    {
        c[i][i]=c[i-1][i-1]+a[i][i];

    }

    printf("\n");

    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=m-n+i+1; j++)
        {
            if((c[i-1][j-1] + a[i][j]) > c[i][j-1])
            {
                c[i][j] = c[i-1][j-1] + a[i][j];
            }
            else
                {
                    c[i][j] = c[i][j-1];
                }
        }
    }
    printf("Vegso Matrix: \n");
     for(int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {

            printf("%i ; ", c[i][j]);
        }
        printf("\n");
    }


    return 0;
}
