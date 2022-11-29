#include <stdio.h>

int main(){
    int qtdEqp, corrida = 0, salto = 0, lancamento = 0, totalAtletas;
    char modalidade;

    scanf("%d",&qtdEqp);
    
    while(qtdEqp > 0){
        getchar();
        scanf("%c",&modalidade);
        while(modalidade != 'F'){
            if(modalidade == 'C'){
                corrida++;
            }
            if(modalidade == 'S'){
                salto++;
            }
            if(modalidade == 'L'){
                lancamento++;
            }
            getchar();
            scanf("%c",&modalidade);
        }
        qtdEqp--;
    }

    totalAtletas = corrida + salto + lancamento;
    
    printf("%d %d %d %d", corrida, salto, lancamento, totalAtletas);

    return 0;
}