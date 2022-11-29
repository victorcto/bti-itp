#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101

int repetido(int indices[], int tam, int indice){
    for(int i=0; i<tam; i++){
        if(indices[i] == indice){
            return 1;
        }
    }

    return 0;
}

int main(){
    int n = 0, s, cont = 0, c = 0;
    char **participantes;

    participantes = (char**) malloc(MAX * sizeof(char*));

    participantes[n] = (char*) malloc(MAX * sizeof(char));
    fgets(participantes[n],MAX,stdin);
    
    while(strcmp(participantes[n],"acabou") != 10){
        n++;
        participantes[n] = (char*) malloc(MAX * sizeof(char));
        fgets(participantes[n],MAX,stdin);
    }

    int indice_participante, indices[n];
   
    scanf("%i",&s);
    srand(s);

    for(int i=0; i<n; i++){
        indice_participante = rand() % n;
        while(repetido(indices,i,indice_participante) == 1){
            indice_participante = rand() % n;
        }
        indices[i] = indice_participante;
        printf("%s",participantes[indice_participante]);
    }

    for(int i=0; i<n; i++){
        free(participantes[i]);
    }

    free(participantes);

    return 0;
}
