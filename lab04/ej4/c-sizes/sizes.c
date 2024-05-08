#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "data.h"

void print_data(data_t d) {
  printf("NOMBRE: %s\n"
         "EDAD  : %d años\n"
         "ALTURA: %d cm\n\n",
         d.name, d.age, d.height);
}

int main(void) {

  data_t messi = {"Leo Messi", 36, 169};
  print_data(messi);

  printf("name-size  : %lu bytes\n"
         "age-size   : %lu bytes\n"
         "height-size: %lu bytes\n"
         "data_t-size: %lu bytes\n",
         sizeof(messi.name), sizeof(messi.age), sizeof(messi.height),
         sizeof(messi));
  long unsigned totalsize = 0;
  totalsize = sizeof(messi.name) + sizeof(messi.age) + sizeof(messi.height);
  printf("Suma de los miembros = %lu bytes\n", totalsize);
  printf("-----------------|||-----------------------\n");
  name_t *c = NULL;
  unsigned int *p = NULL;
  data_t *q = NULL;
  c = &messi.name;
  printf("name memory address  : %p\n", (void *)c);
  p = &messi.age;
  printf("age memory address   : %p\n", (void *)p);
  p = &messi.height;
  printf("height memory address: %p\n", (void *)p);
  q = &messi;
  printf("data_t memory address: %p\n", (void *)q);
  printf("-----------------|||-----------------------\n");
  c = &messi.name;
  printf("name memory index  : %lu\n", (uintptr_t)c);
  p = &messi.age;
  printf("age memory index   : %lu\n", (uintptr_t)p);
  p = &messi.height;
  printf("height memory index: %lu\n", (uintptr_t)p);
  q = &messi;
  printf("data_t memory index: %lu\n", (uintptr_t)q);

  return EXIT_SUCCESS;
}
/*
 * La suma no de los miembros no coincide con el total.
 * El tamaño del campo name no depende de el nombre que contenga pues su tamaño
 * está definido en data.h
 *
 */
