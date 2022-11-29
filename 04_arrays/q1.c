#include <stdio.h>

int main(){
    int n, d, maior = 0;

    scanf("%i", &n);

    int v[n];

    for(int i=0; i<n; i++){
        scanf("%i", &v[i]);
    }

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            d = v[i] + v[j] + (j-i);
            if(d > maior){
                maior = d;
            }
        }
    }

    printf("%i\n", maior);

    return 0;
}