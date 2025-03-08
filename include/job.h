#ifndef __JOB_H
#define __JOB_H

#include <sys/types.h>
#include <termios.h>
#include <stddef.h>

#include "process.h"

typedef struct job
{
    struct job* next;
    char *command;
    process *first_process;
    pid_t pgid;
    char notified;
    struct termios tmodes;
    int stdin, stdout, stderr;
} job;

job *first_job = NULL;

job *
find_job (pid_t pgid) {
    job *j;

    for (j = first_job; j; j = j->next)
        if (j->pgid == pgid)
            return j;
    return NULL;
}

int
job_is_stopped(job *j)
{
    process *p;

    for (p = j->first_process; j; j = j->next)
        if (!p->completed && !p->stopped)
            return 0;
    return 1;
}

int
job_is_completed(job *j)
{
    process *p;
    
    for (p = j->first_process; p; p = p->next)
        if (!p->completed)
            return 0;
    return 1;
}

#endif
