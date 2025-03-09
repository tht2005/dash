#ifndef __JOB_H
#define __JOB_H

#include <sys/types.h>
#include <sys/wait.h>
#include <termios.h>
#include <unistd.h>

#include <errno.h>

#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

typedef struct process
{
    struct process *next;
    char **argv;
    pid_t pid;
    char completed;
    char stopped;
    int status;
} process;

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


// shell.c
extern pid_t shell_pgid;
extern struct termios shell_tmodes;
extern int shell_terminal;
extern int shell_is_interactive;

void
launch_process (process *p, pid_t pgid,
                int infile, int outfile, int errfile,
                int foreground);

int
mark_process_status (pid_t pid, int status);

job *
find_job (pid_t pgid);

int
job_is_stopped(job *j);

int
job_is_completed(job *j);

void
wait_for_job (job *j);

void
put_job_in_background (job *j, int cont);

void
put_job_in_foreground (job *j, int cont);

void
update_status (void);

void
mark_job_as_running (job *j);

void
continue_job (job *j, int foreground);

void
free_job (job *j);

void
format_job_info (job *j, const char *status);

void
do_job_notification (void);

void
launch_job (job *j, int foreground);

#endif
