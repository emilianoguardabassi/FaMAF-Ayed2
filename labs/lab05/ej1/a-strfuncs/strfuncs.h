#ifndef _STRFUNCS_H_
#define _STRFUNCS_H_
#include <stdbool.h>
#include <stdlib.h>

size_t string_length(const char *str);
// calculates the string length pointed by str.

char *string_filter(const char *str, char c);
// returns a new string on the dynamic memory that is obtained by
// taking only the chars that are different to c.

bool string_is_symmetric(const char *str);
// checks if the string is palindrome

#endif // !_STRFUNCS_H_
#define _STRFUNCS_H_
