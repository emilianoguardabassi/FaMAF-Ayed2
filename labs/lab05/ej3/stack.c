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
  s = malloc(sizeof(struct _s_stack));
  s->size = 0u;
  s->capacity = STARTER_CAPACITY;
  s->elems = NULL;
  s->elems = calloc(STARTER_CAPACITY, sizeof(stack_elem));
  return s;
}

stack stack_push(stack s, stack_elem e) {
  if (s->capacity <= s->size) {
    s->capacity = s->capacity + STARTER_CAPACITY;
    s->size++;
    s->elems = realloc(s->elems, sizeof(stack_elem) * s->capacity);
  } else {
    s->size++;
  }

  s->elems[s->size - 1] = e;

  return s;
}

stack stack_pop(stack s) {
  assert(!stack_is_empty(s));
  s->size--;
  return s;
}

unsigned int stack_size(stack s) { return s->size; }

stack_elem stack_top(stack s) {
  assert(!stack_is_empty(s));
  return s->elems[s->size - 1];
}

bool stack_is_empty(stack s) { return s == NULL || s->size == 0; }

stack_elem *stack_to_array(stack s) {
  stack_elem *array = NULL;
  if (s == 0) {
    return NULL;
  } else {
    array = calloc(s->size, sizeof(stack_elem));
    for (size_t i = 0; i < s->size; i++) {
      array[i] = s->elems[i];
    }
    return array;
  }
}

stack stack_destroy(stack s) {
  free(s->elems);
  free(s);
  return s;
}
