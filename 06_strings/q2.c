#include <stdio.h>
#define MAX 1000

int tamanho(char seq[]){
    int cont = 0;

    for(int i=0; i<MAX; i++){
       if(seq[i] != '\0'){
           cont++;
       } 
       else{
           return cont;
       }
    }
}

int main() {
    int cont = 0, cont2 = 0, x = 0, k = 0;
    char seq[MAX];

    scanf("%s",seq);

    for(int i=0; i<tamanho(seq)-1; i++){
        while(x<4){
            if(seq[k] < seq[k]+1 && seq[k+1] == seq[k]+1){
                cont++;
            }
            else{
                break;
            }
            k++;
            x++;
        }
        k++;
        if(cont == 4){
            cont2++;
        }
        x = 0;
        cont = 0;
    }

    if(cont2 == 0){
        printf("nenhuma sequencia encontrada\n");
    }
    else{
        printf("%i\n",cont2);
    }
    
}
