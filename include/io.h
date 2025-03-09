#ifndef __IO_H
#define __IO_H

#include <stdio.h>

#include "dalloc.h"

char*
dfgets (FILE* stream);

void
freebuf ();

#endif
