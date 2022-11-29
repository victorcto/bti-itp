#include <stdio.h>
#include <string.h>

int main() {
    // ========================== Leitura dos dados ==========================

    int n; // Ler prefixos
    scanf("%i",&n);
    char prefixos[n][11];
    for(int i=0; i<n; i++){
        scanf("%s",prefixos[i]);
    }

    int m; // Ler sufixos
    scanf("%i",&m);
    char sufixos[m][11];
    for(int i=0; i<m; i++){
        scanf("%s",sufixos[i]);
    }

    int p = 0; // Ler palavras
    char palavras[p][101];
    scanf("%s",palavras[p]);
    while(strcmp(palavras[p],"-1") != 0){
        p++;
        scanf("%s",palavras[p]);
    }

    // ========== Chechar se em palavras existem algum dos prefixos ==========
    
    int v1 = 0, v2 = 0, c = 0;
    char nova[101];

    for(int i=0; i<p; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<strlen(prefixos[j]); k++){
                if(palavras[i][k] != prefixos[j][k]){
                    v1 = 1;
                    break;
                }
            }
        }
        for(int j=0; j<m; j++){
            for(int k=strlen(palavras[i])-1; k>=0; k--){
                if(palavras[i][k] != sufixos[j][c]){
                    v2 = 1;
                    break;
                }
                c++;
            }
            c = 0;
        }
        c = 0;
        if(v1 == 0 && v2 == 0){
            printf("%s\n",palavras[i]);
        }
        // else if(v1 == 1 && v2 == 0){
        //     for(int j=0; j<strlen(palavras[i]); j++){
        //         for(int k=0; k<n; k++){
        //             for(int l=0; l<strlen(prefixos[k]); l++){
        //                 if(palavras[i][j] != prefixos[k][l]){
        //                     nova[c] = palavras[i][j];
        //                     c++;
        //                 }
                        
        //             }
        //         }
        //     }
        //     printf("%s\n",nova);
        //     c = 0;
            
        // }
        // else if(v1 == 0 && v2 == 1){
        //     for(int j=strlen(palavras[i]); j>0; j--){
        //         for(int k=0; k<m; k++){
        //             for(int l=0; l<strlen(sufixos[k]); l++){
        //                 if(palavras[i][j] != sufixos[k][l]){
        //                     nova[c] = palavras[i][j];
        //                     c++;
        //                 }
        //             }
        //         }
        //     }
        //     printf("%s\n",nova);
        //     c = 0;
        // }
        // else{
        //     for(int j=0; j<strlen(palavras[i]); j++){
        //         for(int k=0; k<n; k++){
        //             for(int l=0; l<strlen(prefixos[k]); l++){
        //                 if(palavras[i][j] != prefixos[k][l]){
        //                     nova[c] = palavras[i][j];
        //                     c++;
        //                 }
        //             }
        //         }
        //     }
        //     for(int j=strlen(palavras[i]); j>0; j--){
        //         for(int k=0; k<m; k++){
        //             for(int l=0; l<strlen(sufixos[k]); l++){
        //                 if(palavras[i][j] != sufixos[k][l]){
        //                     nova[c] = palavras[i][j];
        //                     c++;
        //                 }
        //             }
        //         }
        //     }
        //     if(nova != '\0'){
        //         printf("%s",nova);
        //     }
        //     c = 0;
        // }
        v1 = 0;
        v2 = 0;
    }


    return 0;
}