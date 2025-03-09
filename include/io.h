#ifndef __IO_H
#define __IO_H

#include <stdio.h>

#include "dalloc.h"

#ifndef DFGETS_INIT_BUFFER_LEN
#define DFGETS_INIT_BUFFER_LEN              64
#endif

char*
dfgets (FILE* stream);

void
freebuf ();

#endif
