#include <stdio.h>

int find_values(int row, int aux_row, int col, int aux_col, int mat[][col]);
int min(int row, int aux_row, int col, int aux_col, int mat[][col]);
int max(int row, int aux_row, int col, int aux_col, int mat[][col]);

int main(){          
    int col, row;

    scanf("%d %d", &row, &col);

    int mat[row][col], aux_row = row, aux_col = 0;

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            scanf("%d", &(mat[i][j]));
        }
    }

    find_values(row,aux_row,col,aux_col,mat);

    return 0;

}

int find_values(int row, int aux_row, int col, int aux_col, int mat[][col]){
    if(aux_col == col){
        return aux_col;
    }

    printf("Municipio %i: %i %i\n",aux_col+1,min(row,aux_row,col,aux_col,mat), max(row,aux_row,col,aux_col,mat));

    return find_values(row,aux_row,col,aux_col+1,mat);
}

int min(int row, int aux_row, int col, int aux_col, int mat[][col]){
    if(aux_row == 1){
        return mat[0][aux_col];
    }

    int m = min(row,aux_row-1,col,aux_col,mat);

    if(m < mat[aux_row-1][aux_col]){
        return m;
    }

    return mat[aux_row-1][aux_col];
}

int max(int row, int aux_row, int col, int aux_col, int mat[][col]){
    if(aux_row == 1){
        return mat[0][aux_col];
    }

    int m = max(row,aux_row-1,col,aux_col,mat);

    if(m > mat[aux_row-1][aux_col]){
        return m;
    }

    return mat[aux_row-1][aux_col];
}
