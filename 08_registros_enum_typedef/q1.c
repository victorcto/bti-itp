#include <stdio.h>

typedef struct{
    char nome[201];
    int pontos;
    int total_partidas;
    int vitorias;
    int empates;
    int derrotas;
    int gols_feitos;
    int gols_sofridos;
    int saldo_gols;
} Time;

void leitura(Time times[], int qtd);
void impressao(Time times[], int qtd);

int main(){
    int T;

    scanf("%i", &T);

    Time times[T], aux;

    leitura(times,T);

    for(int i=0; i<T; i++){
        times[i].pontos = times[i].vitorias * 3 + times[i].empates;
        times[i].total_partidas = times[i].vitorias + times[i].empates + times[i].derrotas;
        times[i].saldo_gols = times[i].gols_feitos - times[i].gols_sofridos;
    }

    for(int i=1; i<T; i++){
        for(int j=0; j<T-1; j++){
            if(times[j].pontos < times[j+1].pontos){
                aux = times[j];
                times[j] = times[j+1];
                times[j+1] = aux;
            }
            else if(times[j].pontos == times[j+1].pontos){
                if(times[j].vitorias < times[j+1].vitorias){
                    aux = times[j];
                    times[j] = times[j+1];
                    times[j+1] = aux;
                }
                else if(times[j].vitorias == times[j+1].vitorias) {
                    if(times[j].saldo_gols < times[j+1].saldo_gols){
                        aux = times[j];
                        times[j] = times[j+1];
                        times[j+1] = aux;
                    }
                }
            }
        }
    }

    impressao(times,T);

    return 0;
}

void leitura(Time times[], int qtd){
    for(int i=0; i<qtd; i++){
        scanf("%[^;]s",times[i].nome);
        scanf(";%i",&times[i].vitorias);
        scanf("%i",&times[i].empates);
        scanf("%i",&times[i].derrotas);
        scanf("%i",&times[i].gols_feitos);
        scanf("%i",&times[i].gols_sofridos);
    }
}

void impressao(Time times[], int qtd){
    printf("Tabela do campeonato:\n");
    printf("Nome| Pontos| Jogos| Vitorias| Empates| Derrotas| Gols Pro| Gols Contra| Saldo de Gols");
    for(int i=0; i<qtd; i++){
        printf("%s| %i| %i| %i| %i| %i| %i| %i| %i",times[i].nome,times[i].pontos,times[i].total_partidas,times[i].vitorias,times[i].empates,times[i].derrotas,times[i].gols_feitos,times[i].gols_sofridos,times[i].saldo_gols);
    }

    printf("\n\nTimes na zona da libertadores:");
    for(int i=0; i<6; i++){
        printf("%s",times[i].nome);
    }

    printf("\n\nTimes rebaixados:");
    for(int i=qtd; i>=qtd-4; i--){
        printf("%s",times[i].nome);
    }
}