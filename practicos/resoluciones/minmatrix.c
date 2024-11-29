#include <stdlib.h>
#include <stdio.h>
#define N 10
#define M 10

void init_mx(int filas, int columnas, int matriz[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = i + j + 10 ;  // Ejemplo: llenar con suma de índices
        }
    }
    matriz[5][7] = -20;
}
void print_mx(int filas, int columnas, int matriz[filas][columnas]){
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}
int main(void)
{
    int matrix[N][M];
    init_mx(N,M,matrix);
    print_mx(N, M, matrix);
    int min = matrix[0][0];
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (min > matrix[i][j]) {
                min = matrix[i][j];
            }
        }
    }
    printf("Mínimo = %d\n",min);


    return EXIT_SUCCESS;
}
