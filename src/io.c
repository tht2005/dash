#include "io.h"

char *buf=NULL;
int buflen, curlen;

void extendbuf() {
    buf = drealloc(buf, buflen <<= 1);
}

void freebuf() {
    if(buf) {
        free(buf);
        buf = NULL;
    }
}

char* dfgets(FILE* stream) {
    buf = (char*) dalloc (DFGETS_INIT_BUFFER_LEN * sizeof(char));
    buflen = DFGETS_INIT_BUFFER_LEN;
    curlen = 0;
    int c;
    while( (c = fgetc(stream)), (c != EOF && c != '\n') ) {
        if( (curlen + 2) > buflen ) {
            extendbuf();
        }
        buf[curlen++] = c;
    }
    buf[curlen] = 0;
    return buf;
}
