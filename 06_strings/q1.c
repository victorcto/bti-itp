#include <stdio.h>
#define MAX 11

int similaridade(char s1[], char s2[]);
int maior_palavra(char s1[], char s2[]);
int tamanho(char s[]);
void espaco();

int main() {
    int n;

    scanf("%i",&n);

    char palavra[n+1][MAX], saida[n+1][10];
    getchar();

    for(int i=0; i<n; i++){
        scanf("%s",palavra[i]);
    }
    for(int i=0; i<n+1; i++){
        if(i>0){
            printf("%-10s", palavra[i-1]);
            
        }
        for(int j=0; j<n+1; j++){
            if(i==0 && j==0){
                printf("%-10c",' ');
            }
            if(i==0 && j>0){
                printf("%10s", palavra[j-1]);
            }
            if(i>0 && j<n){
                espaco();
                printf("%i/%i",similaridade(palavra[i-1],palavra[j]),maior_palavra(palavra[i-1],palavra[j]));
            }
            
        }
        printf("\n");
    }
}

void espaco(){
    for(int i=0; i<7; i++){
        printf(" ");
    }
}

int tamanho(char s[]){
    int cont = 0;

    for(int i=0; i<MAX; i++){
        if(s[i] != '\0'){
            cont++;
        }
        else{
            return cont;
        }
    }
}

int maior_palavra(char s1[], char s2[]){
    if(tamanho(s1) > tamanho(s2)){
        return tamanho(s1);
    }
    
    return tamanho(s2);
}

int similaridade(char s1[], char s2[]){
    int cont = 0;

    for(int i=0; i<maior_palavra(s1,s2); i++){
        if(s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0')){
            cont++;
        }
    }

    return cont;
}