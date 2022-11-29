#include <stdio.h>

int main(){
    int A[5][4], codigo, matricula, CR, verificador = 0;

    for(int i=0; i<5; i++){
        for(int j=0; j<4; j++){
            scanf("%i",&A[i][j]);
        }
    }

    scanf("%i",&codigo);

    for(int i=0; i<5; i++){
        if(codigo == A[i][2]){
            matricula = A[i][0];
            CR = A[i][3];
            verificador = 1;
        }
    }

    if(verificador == 1){
        printf("CR = %i\nMatricula = %i\n",CR,matricula);
    }
    else{
        printf("Curso nao existente\n");
    }

    return 0;
}