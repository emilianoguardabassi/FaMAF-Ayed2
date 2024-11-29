#include "pair.h"   /* TAD Par         */
#include <stdio.h>  /* printf()...     */
#include <stdlib.h> /* EXIT_SUCCESS... */

int main(void) {
  pair_t p, q;
  // Nuevo par p
  p = pair_new(3, 4);
  // Se muestra el par por pantalla
  printf("p = ");
  show_pair(p);
  // Nuevo para q con elementos de p intercambiados
  q = pair_swapped(p);
  // Se muestra q
  printf("q = ");
  show_pair(q);
  // Se destruyen p y q
  p = pair_destroy(p);
  q = pair_destroy(q);
  return EXIT_SUCCESS;
}

/*
 * Está bien que falle pues la definición del struct estaba en pair.c y no en
 * pair.h que es la libreria que se importa. Para corregir esto, hay que mover
 * la funcion show_pair a pair.c/pair.h y eliminar el static. Ahora el TAD queda
 * encapsulado.
 */
