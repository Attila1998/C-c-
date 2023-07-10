#include <stdlib.h>
#include <stdbool.h>
int db=0,db1=0;

bool igeretes2(int* x,int k){
    int i;
    for(i=0;i<=k-1;++i){
        if(x[i]==x[k]) {
                return false;
        }
    }
    return true;

}
int main()
{
    int n=4;
    int* x=(int*)calloc(n,sizeof(int*));

     permutacio(x,n,0);
      printf("%i",db1);
    return 0;
}


void kiir(int* x,int n){
int i;

for(i=0;i<n;++i){
    printf("%d ",x[i]);
}
printf("\n");

}

void permutacio(int*x,int n,int k){

for(x[k]=0;x[k]<=n;++x[k]){
    if(igeretes2(x,k)){
        if(k<n-1){
            permutacio(x,n,k+1);
        }else{
            kiir(x,n);
            ++db1;

            kiir(x,n);
        }

    }
}
}

/*void kiirallomanyba(int *x,int n){
FILE* fout=fopen("ki.txt","wt");

int i;

for(i=0;i<n;++i){
    fprintf(fout,"%d ",x[i]);
}
fprintf(fout,"\n");
}
*/
