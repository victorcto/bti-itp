#include <stdio.h>

int main(){
    int A[3][3], aux;

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            scanf("%i",&A[i][j]);
        }
    }

    for(int i=0; i<3; i++){
        aux = A[0][i];
        A[0][i] = A[2][i];
        A[2][i] = aux;
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%i ",A[j][i]);
        }
        printf("\n");
    }

    return 0;
}
