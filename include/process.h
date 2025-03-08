#ifndef __PROCESS_H
#define __PROCESS_H

#include <sys/types.h>

typedef struct process
{
    struct process *next;
    char **argv;
    pid_t pid;
    char completed;
    char stopped;
    int status;
} process;

#endif
