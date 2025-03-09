#include "cpp_string.h"

int
size (string s)
{
    return s->size;
}
int
maxsize (string s)
{
    return s->maxsize;
}
char
*c_str (string s)
{
    return s->s;
}

string
new_string2 (int maxsize)
{
    string s = (__dynamic_char_arr *) dalloc (sizeof (__dynamic_char_arr));
    s->size = 0;
    s->maxsize = maxsize;
    s->s = (char *) dalloc (maxsize * sizeof (char));
    s->s[0] = 0;
    return s;
}

string
new_string ()
{
    return new_string2 (STRING_DEFAULT_MAX_LEN);
}

void
free_string (string s)
{
    free (s->s);
    free (s);
}

void
extend_stringbuf (string s)
{
    if (size (s) + 2 >= maxsize (s))
        s->s = (char *) drealloc (s->s, (s->maxsize <<= 1) * sizeof (char) );
}

void
push_back (string s, char c)
{
    extend_stringbuf (s);
    s->s [s->size ++] = c;
    s->s [s->size] = 0;
}

void
pop_back (string s)
{
    if (s->size <= 0)
    {
        fprintf (stderr, "Can not pop back an empty string\n");
        exit (1);
    }
    s->s [-- (s->size)] = 0;
}
