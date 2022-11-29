#include <stdio.h>

int main(){
    int soma = 0, n = 0;

    for(int i=0; i<4; i++){
        scanf("%i", &n);
        soma += n;
    }

    if(soma == 0){
        printf("Ei! Ninguém colocou nada!");
    }
    else{
        if(soma > 26){
            soma -= 26;
        }
        printf("Letra: %c", (64+soma));
    }

    return 0;
}