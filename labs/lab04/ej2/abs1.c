#include <stdio.h>
#include <stdlib.h>

void absolute(int x, int y) {
  if (x >= 0) {
    y = x;

  } else {
    y = -x;
  }
}

int main(void) {
  int a = 0, res = 0;
  a = -10;
  absolute(a, res);
  printf("res = %d\n", res);

  return EXIT_SUCCESS;
}

/*
El valor que debería mostrarse según el lenguaje del teórico es res=10,
pero el valor que se obtiene es res=0 puesto que la funcion no devuelve
el parametro res escrito.
*/
