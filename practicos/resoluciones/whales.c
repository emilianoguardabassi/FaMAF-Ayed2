
#include <stdio.h>
#include <stdlib.h>

// Función de comparación para qsort (orden ascendente)
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Función para salvar el mayor número de ballenas
int save_whales(int *s, int n, int t) {
    // Ordenar los tiempos de supervivencia en orden ascendente
    qsort(s, n, sizeof(int), compare);

    int saves = 0;          // Contador de ballenas salvadas
    int time_spent = 0;     // Tiempo acumulado en los rescates

    for (int i = 0; i < n; i++) {
        // Si el tiempo acumulado más el tiempo del rescate es menor o igual al tiempo de supervivencia
        if (time_spent + t <= s[i]) {
            saves++;                 // Salvar la ballena
            time_spent += t;         // Actualizar el tiempo acumulado
        }
    }

    return saves;  // Retornar la cantidad máxima de ballenas salvadas
}

int main() {
    // Entrada: tiempos de supervivencia de las ballenas
    int s[] = {7, 3, 2, 5, 10,2,3,50,41,23};
    int n = sizeof(s) / sizeof(s[0]); // Número de ballenas
    int t = 7; // Tiempo constante para rescatar una ballena

    // Llamar a la función y mostrar el resultado
    int result = save_whales(s, n, t);
    printf("Número máximo de ballenas salvadas: %d\n", result);

    return 0;
}
