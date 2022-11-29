#include <stdio.h>

int main(){
    int contAtletas = 0, series;
    float tempoMax, tempoAtletas;

    scanf("%f",&tempoMax);
    scanf("%f",&tempoAtletas);

    while(tempoAtletas != -1){
        if(tempoAtletas <= tempoMax){
            contAtletas++;
        }
        scanf("%f",&tempoAtletas);
    }

    series = contAtletas / 8;

    if(contAtletas == 0){
        series = 0;
    }
    else if(contAtletas <= 8){
        series = 1;
    }
    else if(series >= 1 && contAtletas % 8 != 0){
        series++;
    }

    printf("%d %d", contAtletas, series);

    return 0;
}