#include <stdio.h>
#include <math.h>

int leitura(float saida[], int n, int n2);
int desvio_padrao(float xi[], int n, int n2, double soma, double soma2, double* resultado);

int main(){
    int n;
    double soma = 0.0, soma2 = 0.0, resultado;

    scanf("%i",&n);

    float saida[n];

    leitura(saida,n,0);

    desvio_padrao(saida,n,0,soma,soma2,&resultado);

    printf("%.4f\n",resultado);

    return 0;
}

int leitura(float saida[], int n, int n2){
    if(n2 == n){
        return n;
    }

    scanf("%f",&saida[n2]);

    return leitura(saida,n,n2+1);
}

int desvio_padrao(float xi[], int n, int n2, double soma, double soma2, double* resultado){
    if(n2 == n){
        return n;
    }

    soma += (xi[n2]);
    soma2 += (pow(xi[n2],2));

    printf("soma normal: %f; soma ao quadrado: %f\n",soma,soma2);

    *resultado = sqrt(soma2/n - pow((soma/n),2));

    return desvio_padrao(xi,n,n2+1,soma,soma2,resultado);
}  