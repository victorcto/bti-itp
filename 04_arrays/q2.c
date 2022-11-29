#include <stdio.h>

int main(){
    int qtdAmigos, ganhador, bebidasPetiscos, restante, total = 0;
    float soma = 0.0, k, ganhos, migalhas = 0.0, verificador = 0;

    scanf("%i", &qtdAmigos);

    int val[qtdAmigos], ind[qtdAmigos];

    for(int i=0; i<qtdAmigos; i++){
        scanf("%i", &val[i]);
        scanf("%i", &ind[i]);
    }

    scanf("%i", &ganhador);

    for(int i=0; i<qtdAmigos; i++){
        total += val[i];
    }

    printf("Total: R$ %i\n",total);

    bebidasPetiscos = total * 0.1; 
    restante = total - bebidasPetiscos;

    for(int i=0; i<qtdAmigos; i++){
        if(ganhador == ind[i]){
            soma += val[i];
        }
    }
    
    k = restante / soma;

    for(int i=0; i<qtdAmigos; i++){
        if(ganhador == ind[i]){
            ganhos = val[i] * k;
            migalhas += ganhos - (int) (ganhos); 
            printf("Apostador %i: R$ %i\n",i+1,(int) ganhos);
            verificador = 1;
        }
    }

    if(verificador == 0){
        for(int i=0; i<qtdAmigos; i++){
            soma += val[i];
        }
        k = restante / soma;
        for(int i=0; i<qtdAmigos; i++){
            ganhos = val[i] * k;
            migalhas += ganhos - (int) (ganhos); 
            printf("Apostador %i: R$ %i\n",i+1,(int) ganhos);
        }
    }

    printf("Bebidas e petiscos: R$ %i",(int) (migalhas+bebidasPetiscos));

    return 0;
}