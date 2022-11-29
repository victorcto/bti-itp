#include <stdio.h>

int main(){
    int ano, anocomRegistro = 0;
    float distancia, totaldistancia = 0, indice;

    scanf("%d",&ano);

    for(int i=0; i<ano; i++){
        scanf("%f",&distancia);
        if(distancia != -1){
            totaldistancia += distancia;
            anocomRegistro++;
        }
    }

    if(totaldistancia == 0){
        printf("A competicao nao possui dados historicos!");
    }
    else{
        indice = totaldistancia / anocomRegistro;
        printf("%.2f", indice);
    }

    return 0;
}