#include <stdio.h>
#include <string.h>
#define MAX 256

int main() {
    int aux = -1, aux2 = 0, aux3 = 0;
    int cont = 0, cont2 = 0, cont3 = 0;
    int espaco = 0, espacoTotal = 0;
    float frequencia, frequenciaTotal;
    char palavra[MAX], frases[MAX][MAX];

    scanf("%s",palavra);
    fgets(frases[aux],MAX,stdin);
    while(strcmp(frases[aux],"-1\0")!=10){ 
        aux++;
        fgets(frases[aux],MAX,stdin);
    }

    for(int i=0; i<aux; i++){ 
        for(int j=aux2; j<strlen(frases[i])-1; j++){
            aux3 = 0;
            if(frases[i][j] == ' '){
                espaco++;
                espacoTotal++;
                for(int k=j+1; frases[i][k]!=' '; k++){
                    if(frases[i][k] == palavra[aux3]){
                        cont++;
                    }
                    else{
                        break;
                    }
                    aux2++;
                    aux3++;
                }
                if(cont == strlen(palavra)){
                    cont2++;
                    cont3++;
                }
            }
            cont = 0;
        }
        frequencia = (float) cont2 / (espaco + 1);
        printf("%.4f\n",frequencia);
        espaco = 0;
        aux2 = 0;
        cont2 = 0;
    }

    frequenciaTotal = (float) cont3 / (espacoTotal + aux);
    printf("%.4f\n",frequenciaTotal);

    return 0;
}