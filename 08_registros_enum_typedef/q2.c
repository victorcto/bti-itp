#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id_cartela;
    int tam_cartela;
    int *numeros;
    int *marcacao;
} Cartela;

void inicializa_cartela(Cartela cartela, int id, int N, int M);
int numSorteado(int *cartela, int sorteado);
int repetido(int numeros[], int tam, int numero){
    for(int i=0; i<tam; i++){
        if(numeros[i] == numero){
            return 1;
        }
    }

    return 0;
}

int main(){
    int N, M, S, cont = 0;
    char ler[20];

    scanf("%i",&N);
    scanf("%i",&M);
    scanf("%i",&S);
    srand(S);

    Cartela cartela, cartelas[100];
    getchar();
    while(strcmp(fgets(ler,20,stdin),"Comecou o jogo!")!=10){
        scanf("%i",&cartelas[cont].id_cartela);
        inicializa_cartela(cartela,cont,N,M);
        cartelas[cont].numeros = cartela.numeros;
        cont++;
    }

    for(int i=0; i<cont-1; i++){
        printf("Carterlas %i:\n",cartelas[i].id_cartela);
        
    }

    return 0;
}

void inicializa_cartela(Cartela cartela, int id, int N, int M){
    int numero, numeros[N];
    srand(id);
    for(int i=0; i<N; i++){
        numero = rand() % M;
        while(repetido(numeros,i,numero) == 1){
            numero = rand() % M;
        }
        numeros[i] = numero;
    }
    cartela.numeros = numeros;
}