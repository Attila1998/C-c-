#include <stdio.h>
#include <stdlib.h>
 int Tcompare(const void*,const void*);
int main()
{

    FILE* fin;
    fin=fopen("bemenet.txt","rt");
    int n,m,j,i;
    fscanf(fin,"%d%d",&n,&m);
    printf("%i %i ",n,m);
    printf("\n");
    int **t;
    t=(int**)calloc(n,sizeof(int));
        for(i=0;i<n;++i)
        {
            t[i]=(int*)calloc(m,sizeof(int));
        }


    for(i=0;i<n;++i){
        for(j=0;j<m;++j)
        {fscanf(fin,"%d",&t[i][j]);}
    }

    for(i=0;i<n;++i){
        for(j=0;j<m;++j)
        {printf("%d ",t[i][j]);}
        printf("\n");
    }

//soronkenti rendezes
    for(i=0;i<n;i++)
    {
        qsort(t[i],m,sizeof(int),Tcompare);
    }
printf("\n");
printf("rendezett tomb: \n");
    for(i=0;i<n;++i)
        {
        for(j=0;j<m;++j)
        {printf("%d ",t[i][j]);}
        printf("\n");
    }
    for(i=0;i<n;i++)
    {
        free(t[i]);
    }
    free(t);
    fclose(fin);
return 0;
}

int Tcompare ( const void *p1, const void *p2 )
{
return(*(int*)p1 - *(int*)p2);
}
