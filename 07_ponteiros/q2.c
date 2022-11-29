#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void soma_vetores(int a[], int b[], int c[]);

int main(){
    int *a = malloc(MAX * sizeof(int));
    int *b = malloc(MAX * sizeof(int));
    int tamA = 0, tamB = 0;
    int c[MAX];

    for(int i=0; i<MAX; i++){
        scanf("%i",&a[i]);
        if(getchar() == 10){
            break;
        }
        tamA++;
    }

    for(int i=0; i<MAX; i++){
        scanf("%i",&b[i]);
        if(getchar() == 10){
            break;
        }
        tamB++;
    }

    if(tamA != tamB){
        printf("Vetores de tamanhos diferentes!");
    }
    else{
        soma_vetores(a,b,c);
        for(int i=0; i<tamA+1; i++){
            printf("%i ",c[i]);
        }
        printf("\n");
    }

    return 0;
}

void soma_vetores(int a[], int b[], int c[]){
    for(int i=0; i<MAX; i++){
        c[i] = a[i]+b[i];
    }
}