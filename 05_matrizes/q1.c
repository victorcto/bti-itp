#include <stdio.h>

int main(){
    int A[3][5], soma = 0;

    for(int i=0; i<3; i++){
        for(int j=0; j<5; j++){
            scanf("%i",&A[i][j]);
        }
    }

    printf("SL = [");
    for(int i=0; i<3; i++){
        for(int j=0; j<5; j++){
            soma += A[i][j];
        }
        if(i == 2){
            printf("%i",soma);
        }
        else{
            printf("%i ",soma);
        }
        soma = 0;
    }
    printf("]\n");

    return 0;
}