#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
    int i=0;
    while (s[i] != '\0' && i < FIXSTRING_MAX)
    {
        i++;
    }
    
    return i+1;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    bool eq = true;
    unsigned int s1length,s2length;
    s1length=fstring_length(s1);
    s2length=fstring_length(s2);
    if (s1length==s2length)
    {
        for (unsigned int i = 0; i < s1length; i++)
        {
        eq = eq && (s1[i]==s2[i]);
        }    
    }
    else
    {
        eq=false;
    }

    return eq;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    bool eq_less=true;
    unsigned int s1length,s2length;
    s1length=fstring_length(s1);
    s2length=fstring_length(s2);
    if (s1length <= s2length)
    {
        for (unsigned int i = 0; i < s1length; i++)
        {
            eq_less = eq_less && (s1[i]<=s2[i]);
        }
    }
    else
    {
        for (unsigned int i = 0; i < s2length; i++)
        {
            eq_less = eq_less && (s1[i]<=s2[i]);
        }
    //ver caso que sean iguales por el length de s2 pero s1 sea màs largo    
    }
    return eq_less;
}

