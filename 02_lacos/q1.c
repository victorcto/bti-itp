#include <stdio.h>

int main(){
    int qtd, somaqtd;
    float valor, valortotal;

    scanf("%d",&qtd);
    scanf("%f",&valor);

    somaqtd = qtd;
    valortotal = qtd * valor;

    while(qtd != -1){
        scanf("%d",&qtd);
        if(qtd == -1){
            break;
        }
        scanf("%f",&valor);
        somaqtd += qtd;
        valortotal += qtd * valor;
    }

    printf("%d %.2f\n", somaqtd, valortotal);

    return 0;
}