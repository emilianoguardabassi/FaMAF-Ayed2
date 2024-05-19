#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

#define STARTING_CAPACITY 30

struct s_queue {
  //////
  // unsigned int capacity;
  unsigned int size;
  struct s_node *rear;
  struct s_node *first;
};

struct s_node {
  queue_elem elem;
  struct s_node *next;
};

static struct s_node *create_node(queue_elem e) {
  struct s_node *new_node = malloc(sizeof(struct s_node));
  assert(new_node != NULL);
  new_node->elem = e;
  new_node->next = NULL;
  return new_node;
}

static struct s_node *destroy_node(struct s_node *node) {
  node->next = NULL;
  free(node);
  node = NULL;
  return node;
}

static bool invrep(queue q) { return q != NULL; }

queue queue_empty(void) {
  queue q = NULL;
  q = malloc(sizeof(struct s_queue));
  // q->capacity = STARTING_CAPACITY;
  q->size = 0u;
  q->first = NULL;
  q->rear = NULL;
  assert(invrep(q) && queue_is_empty(q));
  return q;
}

queue queue_enqueue(queue q, queue_elem e) {
  assert(invrep(q));
  struct s_node *new_node = create_node(e);
  if (q->first == NULL) {
    q->first = new_node;
    q->first->next = q->rear;

  } else {
    struct s_node *aux = q->first;
    while (aux->next != NULL) {
      aux = aux->next;
    }
    aux->next = new_node;
    q->rear = aux->next;
  }
  q->size++;
  assert(invrep(q) && !queue_is_empty(q));
  return q;
}

bool queue_is_empty(queue q) {
  assert(invrep(q));
  return q->first == NULL;
}

queue_elem queue_first(queue q) {
  assert(invrep(q) && !queue_is_empty(q));
  return q->first->elem;
}
unsigned int queue_size(queue q) {
  assert(invrep(q));
  unsigned int size = 0;
  size = q->size;
  return size;
}

queue queue_dequeue(queue q) {
  assert(invrep(q) && !queue_is_empty(q));
  struct s_node *killme = q->first;
  q->first = q->first->next;
  killme = destroy_node(killme);
  assert(invrep(q));
  return q;
}

queue queue_disscard(queue q, unsigned int n) {
  assert(invrep(q) && queue_size(q) > n);
  if (n == 0) {
    q = queue_dequeue(q);
  } else {

    struct s_node *aux = q->first;
    for (size_t i = 0; i < n - 1 && aux->next != NULL; i++) {
      aux = aux->next;
    }
    struct s_node *delete = aux->next;
    aux->next = delete->next;
    destroy_node(delete);
  }

  q->size--;
  assert(invrep(q));
  return q;
}

void queue_dump(queue q, FILE *file) {
  file = file == NULL ? stdout : file;
  struct s_node *node = q->first;
  fprintf(file, "[ ");
  while (node != NULL) {
    fprintf(file, "%d", node->elem);
    node = node->next;
    if (node != NULL) {
      fprintf(file, ", ");
    }
  }
  fprintf(file, "]\n");
}

queue queue_destroy(queue q) {
  assert(invrep(q));
  struct s_node *node = q->first;
  while (node != NULL) {
    struct s_node *killme = node;
    node = node->next;
    killme = destroy_node(killme);
  }
  free(q);
  q = NULL;
  assert(q == NULL);
  return q;
}
