#include <stdio.h>

typedef struct{
    int x;
    int y;
} Ponto;

int main(){
    Ponto p1, p2, p3;

    scanf("%i %i %i %i", &p1.x, &p1.y, &p2.x, &p2.y);
    scanf("%i %i", &p3.x, &p3.y);

    int altura, largura;

    altura = p1.y * p2.y;
    largura = p1.x * p2.x;


    if((p3.x >= p1.x && p3.x <= p2.x) && (p3.y >= p1.y && p3.y <= p2.y)){
        printf("Dentro!");
    }
    else{
        printf("Fora!");
    }
    
    return 0;
}