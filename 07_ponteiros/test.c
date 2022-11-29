#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char entrada[11];

    scanf("%s",entrada);

    long dia, mes, ano, i = 0;
    char *pont, *token;

    token = strtok(entrada,"/");

    while (token!=NULL){
        if(i == 0){
            dia = strtol(token, &pont, 10);
        }
        if(i == 1){
            mes = strtol(token, &pont, 10);
        }
        if(i == 2){
            ano = strtol(token, &pont, 10);
        }
        token = strtok(NULL,"/");
        i++;
    }
    printf("%ld-%ld-%ld\n",dia,mes,ano);

    return 0;
}