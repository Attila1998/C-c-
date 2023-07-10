#include <stdio.h>
#include <stdlib.h>
void NevPer(char **nev,int n,int k);
void kiir(char **nev,int n);
int igeretes(char **nev,int k);
void kiirallomanyba(char **nev,int n);
int db=0;
int main()
{
int n,k;
char **nev;
FILE* fin=fopen("Csoport.txt","rt");
fscanf(fin,"%i ",&n);
printf("%i\n",n);

nev=(char*)malloc(n*sizeof(char));
for(int i=0;i<n;i++)
    {
    nev[i]=(char)malloc(n*sizeof(char));
    for(int j=0;j<n;j++)
        {
        fscanf(fin,"%s ",&nev[i][j]);
        }
    }

    for(int i=0;i<n;i++)
        {for(int j=0;j<n;j++)
        {printf("%s" ,nev[i][j]);}
        printf("/n");
        }

        //NevPer(char **nev,int n,int k);

}

void NevPer(char **nev,int n,int k){
for(nev[k]=0;x[k]<=n;++x[k]){
    if(igeretes2(**nev,k)){
        if(k<n-1){
            permutacio(nev,n,k+1);
        }else{
            kiir(nev,n);
            ++db1;

            kiirallomanyba(nev,n);
        }

    }
}
}

int igeretes(char **nev,int k){
    for(int i=1;i<k-1;i++)
    {
        if(nev[i][j]==nev[k]){return 0;}

    }
    return 1;
}

void kiir(char **nev,int n){
int i;

for(i=0;i<n;++i){
    printf("%d ",nev[i][j]);
}
printf("\n");

}

void kiirallomanyba(char **nev,int n){
FILE* fout=fopen("ki.txt","wt");

int i;

for(i=0;i<n;++i){
    fprintf(fout,"%d ",nev[i][j]);
}
fprintf(fout,"\n");
}
