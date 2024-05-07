#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void absolute(int x, int *y) {
  if (x >= 0) {
    *y = x;
  } else {
    *y = -x;
  }
}

int main(void) {
  int a = 0, res = 0;
  a = -10;
  printf("Antes de absolute() res=%d\n", res);
  absolute(a, &res);
  printf("Después de la absolute() res=%d\n", res);
  assert(res >= 0 && (res == a || res == -a));
  return EXIT_SUCCESS;
}
