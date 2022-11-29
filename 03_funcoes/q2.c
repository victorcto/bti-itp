#include <stdio.h>

int testa_pontos(int xC, int yC, int xP1, int yP1, int xP2, int yP2){
    float m;

    if(xP2 - xP1 == 0){
        if(xC == xP1){
            return 1;
        }
        else{
            return 0;
        }
    }

    m = (float)(yP2 - yP1) / (xP2 - xP1);

    if((yC - yP1) == (int)(m * (xC - xP1))){
        return 1;
    }

    return 0;
}


int main(){
    int xC, yC, xP1, yP1, xP2, yP2, xP3, yP3, n, aux, xP1b, yP1b;
    int cont = 0;

    scanf("%i %i %i", &xC, &yC, &n);
    scanf("%i %i", &xP1, &yP1);

    xP1b = xP1; 
    yP1b = yP1;

    for(int i=1; i<n; i++){
        scanf("%i %i", &xP2, &yP2);
        cont += testa_pontos(xC,yC,xP1,yP1,xP2,yP2);
        aux = xP1;
        xP1 = xP2;
        xP2 = aux;
        aux = yP1;
        yP1 = yP2;
        yP2 = aux;
    }

    if(testa_pontos(xC,yC,xP1,yP1,xP1b,yP1b)){
        cont++;
    }

    if(cont > 0){
        printf("S\n");
    }
    else{
        printf("N\n");
    }

    return 0;
}