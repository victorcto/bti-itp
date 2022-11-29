#include <stdio.h>

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

int main(){
  int n;

  scanf("%i",&n);

  int values[n], current[n];

  read_values(values,n);
  print_values(current,n);

  return 0;
}