#include "pair.h"   /* TAD Par         */
#include <stdio.h>  /* printf()...     */
#include <stdlib.h> /* EXIT_SUCCESS... */

static void show_pair(pair_t p) {
  printf("(%d, %d)\n", p.values[0], p.values[1]);
}

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

/*La función falla pues show_pair estaba definido para otra implementación del
 * TAD.
 *
 * El diseño del TAD no logra el encapsulamiento, pues el usuario debe ingresar
 * los datos correctos si quiere, por ejemplo, printear el pair. Debería estar
 * definida una funcion en el TAD que ya lo haga por él.
 */
