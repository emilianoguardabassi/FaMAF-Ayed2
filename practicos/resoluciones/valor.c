#include <stdio.h>

// Estructuras para representar productos y sus requisitos de materia prima
typedef struct {
    int ma; // Materia prima A requerida
    int mb; // Materia prima B requerida
} Materia;

typedef struct {
    int valor;     // Valor del producto
    Materia materias; // Requerimientos de materia prima
} Producto;

// Función de backtracking
int max_valor_backtracking(int MA, int MB, Producto productos[], int cantidad, int idx) {
    // Caso base: No quedan productos por evaluar
    if (idx >= cantidad) {
        return 0;
    }

    // No fabricar este producto
    int valor_sin_producto = max_valor_backtracking(MA, MB, productos, cantidad, idx + 1);

    // Fabricar este producto si es posible
    int valor_con_producto = 0;
    if (productos[idx].materias.ma <= MA && productos[idx].materias.mb <= MB) {
        valor_con_producto = productos[idx].valor +
                             max_valor_backtracking(
                                 MA - productos[idx].materias.ma,
                                 MB - productos[idx].materias.mb,
                                 productos, cantidad, idx + 1);
    }

    // Devolver el máximo entre fabricar o no fabricar este producto
    return (valor_sin_producto > valor_con_producto) ? valor_sin_producto : valor_con_producto;
}

// Programa principal
int main() {
    // Materias primas disponibles
    int MA = 50; // Cantidad disponible de materia prima A
    int MB = 25; // Cantidad disponible de materia prima B

    // Lista de productos
    Producto productos[] = {
        {60, {10, 5}},  // Producto 1: valor = 60, ma = 10, mb = 5
        {100, {20, 10}}, // Producto 2: valor = 100, ma = 20, mb = 10
        {120, {25, 13}}, // Producto 3: valor = 120, ma = 30, mb = 15
        {100, {5, 2}}     // Producto 4: valor = 30, ma = 5, mb = 2
    };

    int cantidad = sizeof(productos) / sizeof(productos[0]);

    // Calcular el valor máximo alcanzable
    int max_valor = max_valor_backtracking(MA, MB, productos, cantidad, 0);

    // Mostrar el resultado
    printf("El valor máximo alcanzable es: %d\n", max_valor);

    return 0;
}
