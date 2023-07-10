#include <stdio.h>
#include <stdlib.h>
void read(FILE*,int*,int);
void write(int*,int);
int int_cmp(const void*, const void*);
void greedy(int*,int,int);
int main()
{
    FILE* fin = fopen("penz.txt","rt");
    if(!fin)
    {
        printf("Hiba!");
        return 0;
    }

    int n ;
    fscanf(fin,"%i",&n);
    printf(" Bankjegyek szama: %i\n",n);
    int sum = 0;
    fscanf(fin,"%i",&sum);
    printf("Osszeg: %i \n",sum);

    int* t;
    t = (int*)calloc(n,sizeof(int));
    if(!t)
    {
        printf("Hiba2!");
        return 0;
    }

    read(fin,t,n);
    write(t,n);
    //rendezes-csokkenobe(qsort)
    qsort(t,n,sizeof(int),int_cmp);
    printf("\nRendezett: \n");
    write(t,n);
    //greedy
    greedy(t,n,sum);
    free(t);
    fclose(fin);
    return 0;
}

void read(FILE* fin, int* t,int n)
{
    for(int i=0; i<n; i++)
        fscanf(fin,"%i ",&t[i]);
}

void write(int* t,int n)
{
    for(int i=0; i<n; i++)
        printf("%i ",t[i]);
}

int int_cmp(const void *p1,const void *p2)
{
    int *q1=(int*)p1;
    int *q2=(int*)p2;
    if(*q1>*q2)
    {
        return 1;
    }
    else if(*q1<*q2)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

void greedy(int* t,int n,int sum)
{
int db,i;
for(i=0;i<n && sum>=0;i++)
{
    db=0;
    //if(t[i]<=sum)

    db=sum/t[i];
    sum=sum%t[i];
    printf("\n %i x %i ;",db,t[i]);

}
}
