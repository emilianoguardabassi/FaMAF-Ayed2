#include "strfuncs.h"
#include <stdio.h>
#include <stdlib.h>

size_t string_length(const char *str) {
  size_t length;
  length = 0;
  if (str == NULL) {
    length = 0;

  } else {

    for (int i = 0; str[i] != '\0'; i++) {
      length += 1;
    }
  }
  return length;
}

char *string_filter(const char *str, char c) {
  if (str == NULL) {
    return NULL;
  }
  size_t length = string_length(str);
  char *nstr = calloc(length, sizeof(char));
  if (nstr != NULL) {
    size_t i = 0, j = 0;
    while (str[i] != '\0') {
      if (str[i] != c) {

        nstr[j] = str[i];
        j++;
      }
      i++;
    }
    nstr[j] = '\0';
  } else {
    fprintf(stderr, "ERROR: string NULL\n");
    abort();
  }
  return nstr;
}

bool string_is_symmetric(const char *str) {
  bool isPalindrome = true;
  size_t length = string_length(str);
  int beginning = 0, end = length - 1;
  while (beginning < end) {
    if (str[beginning] != str[end]) {
      isPalindrome = false;
    }
    beginning++;
    end--;
  }

  return isPalindrome;
}
