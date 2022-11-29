#include <stdio.h>

int main(){
    int A[5][3], qtd, cont = 0;

    for(int i=0; i<5; i++){
        for(int j=0; j<3; j++){
            scanf("%i",&A[i][j]);
        }
    }

    for(int i=0; i<5; i++){
        qtd = A[i][1] - A[i][2];
        if(qtd > 0){
            printf("%i %i\n",A[i][0],qtd);
            cont++;
        }
    }

    if(cont == 0){
        printf("Estoque Completo\n");
    }

    return 0;
}
