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
 * La diferencia entre el Spec de la consigna y el pair.h es que
 * en la consigna se toma pair polimorfico de tipo A mientras que
 * en pair.h solo pueden usarse elem que son unicamente int.
 */
