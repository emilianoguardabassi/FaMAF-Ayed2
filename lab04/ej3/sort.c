/*
  @file sort.c
  @brief sort functions implementation
*/

#include "sort.h"
#include "helpers.h"
#include "player.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool goes_before(player_t x, player_t y) { return (&x->rank <= &y->rank); }

bool array_is_sorted(player_t atp[], unsigned int length) {
  unsigned int i = 1u;
  while (i < length && goes_before(atp[i - 1u], atp[i])) {
    i++;
  }
  return (i == length);
}

void sort(player_t a[], unsigned int length) {
  // completar aquí
}
