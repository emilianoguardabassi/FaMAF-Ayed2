#include "stack.h"
#include <assert.h>
#include <stdlib.h>

struct _s_stack {
  stack_elem elem;
  stack next;
  size_t size;
};

bool invrep(stack s) {
  if (s == NULL) {
    return true;
  } else if (s->size == stack_size(s)) {
    return true;
  } else {
    return false;
  }
}

stack stack_empty() {
  stack s = NULL;

  return s;
}

stack stack_push(stack s, stack_elem e) {
  stack p = malloc(sizeof(struct _s_stack));
  if (s == NULL) {
    p->size = 1;

  } else {
    assert(invrep(s));

    p->size = s->size + 1;
  }
  p->next = s;
  p->elem = e;
  s = p;
  assert(invrep(s));
  return s;
}

stack stack_pop(stack s) {
  assert(invrep(s));
  assert(!stack_is_empty(s));
  stack p = NULL;
  p = s;
  s = s->next;

  free(p);

  assert(invrep(s));
  return s;
}

unsigned int stack_size(stack s) {
  assert(s != NULL);
  return s->size;
}

stack_elem stack_top(stack s) {
  assert(s != NULL);
  assert(invrep(s));
  return s->elem;
}

bool stack_is_empty(stack s) {
  assert(invrep(s));
  return (s == NULL);
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
  while (s != NULL) {
    p = s;
    s = s->next;
    assert(invrep(p));
    free(p);
  }

  return s;
}
