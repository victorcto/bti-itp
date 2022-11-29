#include <stdio.h>

int calculaZ(int xc, int yc, int x2, int y2, int x, int y){
    return (x2 - xc) * (y - yc) - (yc - y) * (x - xc);
}

int main(){
    int N, M, a, b, Xmax, iXmax, cont = 0;

    scanf("%i", &N);
    scanf("%i", &M);

    int vnx[N], vny[N], vmx[M], vmy[M];
    char vmc[M];

    for (int i = 0; i < N; i++){
        scanf("%i", &vnx[i]);
        scanf("%i", &vny[i]);
    }

    for (int i = 0; i < M; i++){
        getchar();
        scanf("%c", &vmc[i]);
        scanf("%i", &vmx[i]);
        scanf("%i", &vmy[i]);
    }

    for (int i = 0; i < N; i++){ // Maior coordenada X
        if (vnx[i] > Xmax){
            Xmax = vnx[i];
        }
    }

    for(int i=0; i<M; i++){
        for(int j=0; j<N-1; j++){
            a = calculaZ(vmx[i],vmy[i],Xmax,vmy[i],vnx[j],vny[j]);
            if((a < 0 && calculaZ(vmx[i],vmy[i],Xmax,vmy[i],vnx[j+1],vny[j+1])>0) || (a > 0 && calculaZ(vmx[i],vmy[i],Xmax,vmy[i],vnx[j+1],vny[j+1]) < 0)){
                cont++;
            }
            if(j == N-2){
                a = calculaZ(vmx[i],vmy[i],Xmax,vmy[i],vnx[j+1],vny[j+1]);
                if((a < 0 && calculaZ(vmx[i],vmy[i],Xmax,vmy[i],vnx[0],vny[0]) > 0) || (a > 0 && calculaZ(vmx[i],vmy[i],Xmax,vmy[i],vnx[0],vny[0]) < 0)){
                    cont++;
                }
            }
        }
        if(cont%2 != 0){
            printf("%c\n",vmc[i]);
        }
        cont = 0;
    }

    return 0;
}