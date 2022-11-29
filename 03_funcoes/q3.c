#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float produto_cruzado(int xC, int yC, int xP1, int yP1, int xP2, int yP2){
    return (xP1 - xP2) * (yP1 - yC) - (yP1 - yP2) * (xP1 - xC);
}


float distancia(int xC, int yC, int xP1, int yP1, int xP2, int yP2){
    float pc, md; 

    pc = produto_cruzado(xC,yC,xP1,yP1,xP2,yP2);
    md = sqrt(pow((xP1 - xP2),2) + pow((yP1 - yP2),2));

    return pc / md;
}

float testa_pontos(int xC, int yC, int xP1, int yP1, int xP2, int yP2){
    if(abs(distancia(xC,yC,xP1,yP1,xP2,yP2)) < 3){
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