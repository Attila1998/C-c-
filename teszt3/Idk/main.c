#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int feltolt(int);

int main()
{
    int n = 5;
    srand(time(NULL));
    for(int i=0;i<n;i++)
    printf("%i ,",feltolt(n));
    return 0;
}

int feltolt(int n)
{
    int *t,i;
    t = (int*) calloc (n,sizeof(int));
    for(int i=0;i<n;i++)
    {
        t[i] = rand()%50-50;
    }
    return t[i];
}
