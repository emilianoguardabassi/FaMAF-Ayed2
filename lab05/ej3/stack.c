#include "stack.h"
#include <assert.h>
#include <stdlib.h>

struct _s_stack {
  stack_elem *elems;     // Arreglo de elementos
  unsigned int size;     // Cantidad de elementos en la pila
  unsigned int capacity; // Capacidad actual del arreglo elems
};

stack stack_empty() {
  stack s = NULL;
  return s;
}

stack stack_push(stack s, stack_elem e) {}
