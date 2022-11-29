#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int diadasemana(char entrada[], char **saida, int *bissexto){
    // Validação do formato

    for(int i=0; i<10; i++){
        if(!((entrada[i] >= '0' && entrada[i] <= '9') || (entrada[i] == '/'))){
            return -2;
        }
    }

    // Pega dia, mes e ano

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

    // Bissexto

    if((ano%400==0) || ((ano%4==0) && (ano%100!=0))){
        *bissexto = 1;
    }
    else{ 
        *bissexto = 0;
    }

    // Validação de datas

    if(mes < 1 || mes > 12){
        return -1;
    }
    else if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || 
    mes == 10 || mes == 12){
        if(dia < 1 || dia > 31){
            return -1;
        }
    }
    else if(mes == 4 || mes == 6 || mes == 11){
        if(dia < 1 || dia > 30){
            return -1;
        }
    }
    else if(mes == 2 && *bissexto == 1){
        if(dia < 1 || dia > 29){
            return -1;
        }
    }
    else if(mes == 2 && *bissexto == 0){
        if(dia < 1 || dia > 28){
            return -1;
        }
    }
    
    // Dias da semana

    int valor;

    valor = (23*mes/9+dia+4+(mes<3?ano--:ano-2)+ano/4-ano/100+ano/400)%7;

    switch (valor){
    case 0:
        *saida = "Domingo";
        break;
    case 1:
        *saida = "Segunda";
        break;
    case 2:
        *saida = "Terça"; 
        break;
    case 3:
        *saida = "Quarta";
        break;
    case 4:
        *saida = "Quinta";
        break;
    case 5:
        *saida = "Sexta";
        break;
    case 6:
        *saida = "Sábado";
        break;
    default:
        break;
    }

    return 1;
}

int main(){
    int status=0, bissexto=0;
    char entrada[11]={0}, *saida=NULL;

    fgets(entrada,11,stdin);
        
    status = diadasemana(entrada,&saida,&bissexto);
        
    if(status>0){
        printf("%s.%s\n",saida,bissexto? " Ano bissexto." : "");       
    }
    else{
        if (status==-1)
            printf("Data inexistente.\n");
        else
            printf("Entrada invalida.\n");
        return 1;
    }

    return 0;
}