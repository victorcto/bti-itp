#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void localizaPalavra(char **cacapalavras, char palavra[], char *e, int *s);
void imprimePalavra(char *c, int salto, int tam);  

int main(){
    int n, s;

    scanf("%i",&n);

    char palavras[n][10], **cacapalavras, *e;

    for(int i=0; i<n; i++){
        scanf("%s",palavras[i]);
    }

    cacapalavras = (char**) malloc(10*sizeof(char*));

    for(int i=0; i<10; i++){
        cacapalavras[i] = (char*) malloc(10*sizeof(char));
    }

    for(int i=0; i<10; i++){
        scanf("%s",cacapalavras[i]);
    }

    for(int i=0; i<n; i++){
        localizaPalavra(&cacapalavras,palavras[i],&e,&s);
        imprimePalavra(e,s,strlen(palavras[i]));
    }
    
    
    for(int i=0; i<10; i++){
        free(cacapalavras[i]);
    }

    free(cacapalavras);
    
    return 0;
}

void localizaPalavra(char **cacapalavras, char palavra[], char *e, int *s){

}

void imprimePalavra(char *c, int salto, int tam){
    if (c==NULL) {
        printf("Palavra nao encontrada\n");
        return;
    }
    for (int i=0; i<tam; i++) {
        printf("%c", *c);
        c+=salto;
    }
    printf(", salto:%d\n", salto);
}