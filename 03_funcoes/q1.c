#include <stdio.h>
#include <math.h>

float testa_pontos(float xClique, float yClique, float xPonto, float yPonto){
    return sqrt(pow((xClique - xPonto),2) + pow((yClique - yPonto),2));
}


int main(){
    float xClique, yClique, xPonto, yPonto;
    int n, cont = 0;

    scanf("%f %f %i", &xClique, &yClique, &n);

    for(int i=0; i<n; i++){
        scanf("%f %f", &xPonto, &yPonto);
        if(testa_pontos(xClique,yClique,xPonto,yPonto) < 3){
            cont++;
        }
    }

    if(cont > 0){
        printf("S");
    }
    else{
        printf("N");
    }

    return 0;
}