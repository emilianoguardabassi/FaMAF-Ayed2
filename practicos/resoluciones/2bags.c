#include <stdio.h>

// Definimos la estructura para un objeto
typedef struct {
    int valor;
    int peso;
} Objeto;

// Función auxiliar para calcular el máximo entre dos enteros
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Función que calcula el valor máximo utilizando backtracking
int back_max_val(Objeto objetos[], int n, int i, int W1, int W2) {
    // Caso base: si no hay más objetos que procesar
    if (i >= n) {
        return 0;
    }

    // Si el objeto actual no cabe en ninguna mochila
    if (objetos[i].peso > W1 && objetos[i].peso > W2) {
        return back_max_val(objetos, n, i + 1, W1, W2);
    }

    // Si el objeto actual solo cabe en la mochila 1
    if (objetos[i].peso > W2) {
        return max(
            objetos[i].valor + back_max_val(objetos, n, i + 1, W1 - objetos[i].peso, W2),
            back_max_val(objetos, n, i + 1, W1, W2)
        );
    }

    // Si el objeto actual solo cabe en la mochila 2
    if (objetos[i].peso > W1) {
        return max(
            objetos[i].valor + back_max_val(objetos, n, i + 1, W1, W2 - objetos[i].peso),
            back_max_val(objetos, n, i + 1, W1, W2)
        );
    }

    // Si el objeto actual cabe en ambas mochilas
    return max(
        objetos[i].valor + back_max_val(objetos, n, i + 1, W1 - objetos[i].peso, W2),
        max(
            objetos[i].valor + back_max_val(objetos, n, i + 1, W1, W2 - objetos[i].peso),
            back_max_val(objetos, n, i + 1, W1, W2)
        )
    );
}

// Función principal
int main() {
    // Definimos los objetos (valor, peso)
    Objeto objetos[] = {
        {2, 2}, {3, 3}, {1725, 150}, {10, 10}, {8, 8},
        {7, 7}, {1, 1}, {4, 4}, {6, 6}, {1000, 20}
    };

    // Número de objetos
    int n = sizeof(objetos) / sizeof(objetos[0]);

    // Capacidades de las mochilas
    int W1 = 150;
    int W2 = 20;

    // Llamada a la función
    int valor_maximo = back_max_val(objetos, n, 0, W1, W2);

    // Imprimir el resultado
    printf("El valor máximo alcanzable es: %d\n", valor_maximo);

    return 0;
}
