#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool igeretes(int*,int);
bool igeretes2(int*,int);
void back_tracking(int*,int,int);
void kiiras(int*,int);
int db=0;


int main()
{
    int n;
    printf("Ennyi szamnak kell a apermutacioja: ");
    scanf("%d",&n);
    int* tomb=(int*)malloc(n*sizeof(int));
    int i;
    for(i=1; i<=n; ++i)
    {
        tomb[i]=i;
    }
    i=1;
    back_tracking(tomb,n,i);
    printf("Ennyi darab van : %d\n",db);


    return 0;
}

void back_tracking(int *tomb ,int n,int i)
{


    for(tomb[i]=1; tomb[i]<=n; ++tomb[i])
    {
        if(igeretes(tomb,i))
        {
            if(i<n)
            {
                back_tracking(tomb,n,i+1);
            }
            else
            {


                if(igeretes2(tomb,n))
                {
                    kiiras(tomb,n);
                    ++db;
                }
            }
        }

    }
}



void kiiras(int* tomb,int n)
{
    int i;
    for(i=1; i<=n; ++i)
    {
        printf("%d ",tomb[i]);
    }
    printf("\n");
}

bool igeretes(int* tomb,int j)
{
    int i;

    for(i = 1 ; i <j ; ++i)
    {


        if(tomb[i]==tomb[j])
        {
            return false;
        }
    }
    return true;


}

bool igeretes2(int* tomb, int n)
{
    bool semmi=false;
    if((tomb[1]==1 || tomb[1]==2) && ( tomb[n]==n || tomb[n]==n-1))
    {
        semmi=true;
        int i;
        for(i=2; i<=n; ++i)
        {

            if(tomb[i]== i-1 || tomb[i]== i || tomb[i]== i+1 )
            {
                bool na_ez_a_semmi_jezusom_de_buta_a_Codeblocks_basszus=true;
            }
            else semmi=false;

        }
    }


    return semmi;
}


