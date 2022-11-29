#include <stdio.h>

void read_values(int values[], int n);
void print_values(int current[], int n);
int n_combinations(int values[], int n);
int generates_combinations(int output[], int n, int x);
int combinations(int current[], int n, int x, int x2, int pos);

int main(){
  int n;

  scanf("%i",&n);

  int values[n], current[n];

  read_values(values,n);
  combinations(values,n,n_combinations(values,n),0,n-1);

  return 0;
}

void read_values(int values[], int n){
  for(int i=0;i<n;i++){
    scanf("%d", &(values[i]));
  }
}

void print_values(int current [], int n){
  printf("<%d", current[0]);

  for(int i=1;i<n;i++){
    printf(", %d", current[i]);    
  }

  printf(">\n");    
}

int n_combinations(int values[], int n){
    if(n == 0){
        return 1;
    }

    return values[n - 1] * n_combinations(values,n-1);
}

int generates_combinations(int output[], int n, int x){
    if(n == 1){
        output[0] = x;
        return n;
    }

    output[n-1] = x;

    return generates_combinations(output,n-1,x);
}

int combinations(int current[], int n, int x, int x2, int pos){
    if(x2 == x){
        generates_combinations(current,n,x2);
        return x;
    }

    generates_combinations(current,n,x2);
    print_values(current,n);

    return combinations(current,n,x,x2+1,n-1);
}

