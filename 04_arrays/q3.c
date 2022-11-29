#include <stdio.h>

int calculaZ(int x1, int y1, int x2, int y2, int xc, int yc){
    return (x2 - x1) * (yc - y1) - (y2 - y1) * (xc - x1);
}

int main(){
    int N, M, z, cont = 0;

    scanf("%i", &N);
    scanf("%i", &M);

    int vnx[N], vny[N], vmx[M], vmy[M];
    char vmc[M];

    for(int i=0; i<N; i++){
        scanf("%i", &vnx[i]);
        scanf("%i", &vny[i]);
    }

    for(int i=0; i<M; i++){
        getchar();
        scanf("%c", &vmc[i]);
        scanf("%i", &vmx[i]);
        scanf("%i", &vmy[i]);
    }

    for(int i=0; i<M; i++){
        for(int j=0; j<N-1; j++){
            z = calculaZ(vnx[j],vny[j],vnx[j+1],vny[j+1],vmx[i],vmy[i]);
            if(z < 0){
                cont++;
            }
            if(j == N-2){
                z = calculaZ(vnx[j+1],vny[j+1],vnx[0],vny[0],vmx[i],vmy[i]);
                if(z < 0){
                    cont++;
                }
            }
        }
        if(cont == N){
            printf("%c\n",vmc[i]);
        }
        cont = 0;
    }

    return 0;
}