#include "stack.h"
#include <assert.h>
#include <stdlib.h>

struct _s_stack {
  stack_elem elem;
  stack next;
  size_t size;
};

bool invrep(stack s) { return s->size == stack_size(s); }

stack stack_empty() {
  stack s = malloc(sizeof(stack));
  s->size = 0;
  s->next = NULL;

  return s;
}

stack stack_push(stack s, stack_elem e) {
  assert(invrep(s));
  stack p = malloc(sizeof(stack));
  p->elem = e;
  p->next = s;
  p->size = s->size + 1;
  s = p;
  assert(invrep(s));
  return s;
}

stack stack_pop(stack s) {
  assert(invrep(s));
  assert(!stack_is_empty(s));
  stack p = NULL;
  stack q = p;
  p = s;
  q = p->next;
  q->size = s->size - 1;
  free(p);

  assert(invrep(q));
  return q;
}

unsigned int stack_size(stack s) { return s->size; }

stack_elem stack_top(stack s) {
  assert(s != NULL);
  assert(invrep(s));
  return s->elem;
}

bool stack_is_empty(stack s) {
  assert(invrep(s));
  return (s->size == 0);
}

stack_elem *stack_to_array(stack s) {
  assert(invrep(s));
  stack_elem *array = NULL;

  if (s == NULL) {
    return NULL;
  }

  stack p = s;
  unsigned int size = stack_size(s) - 1;
  array = calloc(stack_size(s), sizeof(stack_elem));

  while (!stack_is_empty(p)) {
    array[size] = stack_top(p);
    p = p->next;
    size--;
  }
  free(p);
  invrep(s);
  return array;
}

stack stack_destroy(stack s) {
  assert(invrep(s));
  stack p = NULL;
  p = s;

  while (!stack_is_empty(p)) {
    p = stack_pop(p);
  }
  assert(invrep(p));
  free(p);

  return s;
}
