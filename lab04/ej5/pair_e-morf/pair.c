#include "pair.h"
#include <stdio.h>
#include <stdlib.h>
struct s_pair_t {
  elem fst;
  elem snd;
};
pair_t pair_new(elem x, elem y) {

  pair_t pair = NULL;
  pair = malloc(sizeof(pair_t));
  pair->fst = x;
  pair->snd = y;
  return pair;
}

elem pair_first(pair_t p) { return p->fst; }

elem pair_second(pair_t p) { return p->snd; }

pair_t pair_swapped(pair_t p) {

  pair_t q = NULL;
  q = malloc(sizeof(pair_t));
  q->fst = p->snd;
  q->snd = p->fst;
  return q;
}

pair_t pair_destroy(pair_t p) {
  free(p);
  p = NULL;
  return p;
}
void show_pair(pair_t p) { printf("(%d, %d)\n", p->fst, p->snd); }
