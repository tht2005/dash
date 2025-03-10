#ifndef __CPP_STRING_H
#define __CPP_STRING_H

#include <stdlib.h>
#include <stdio.h>

#include "dalloc.h"

typedef struct __dynamic_char_arr
{
    int size;
    int maxsize;
    char *s;
}
__dynamic_char_arr;

typedef __dynamic_char_arr* string;

#ifndef STRING_DEFAULT_MAX_LEN
#define STRING_DEFAULT_MAX_LEN      8
#endif

int
size (string s);

int
maxsize (string s);

char
*c_str (string s);

string
new_string2 (int maxsize);

string
new_string ();

void
free_string (string s);

void
push_back (string s, char c);

void
pop_back (string s);

#endif
