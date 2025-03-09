// int execvpe(const char *file, char *const argv[], char *const envp[]);
#define _GNU_SOURCE
#include <unistd.h>

#include "shell.h"
#include "job.h"

int main()
{
    init_shell();

    // typedef struct process
    // {
    //     struct process *next;
    //     char **argv;
    //     pid_t pid;
    //     char completed;
    //     char stopped;
    //     int status;
    // } process;


    // typedef struct job
    // {
    //     struct job* next;
    //     char *command;
    //     process *first_process;
    //     pid_t pgid;
    //     char notified;
    //     struct termios tmodes;
    //     int stdin, stdout, stderr;
    // } job;

    char *argv[] = { "echo", "hello, world" };
    char *argv2[] = { "tee" };

    process p3 = { NULL, argv2, 0, 0, 0, 0 };
    process p2 = { &p3, argv2, 0, 0, 0, 0 };
    process p1 = { &p2, argv, 0, 0, 0, 0 };

    job j = { NULL, "echo \"Hello, World\"", &p1, 0, 0, shell_tmodes, 0, 1, 2 };

    launch_job(&j, 1);

    return 0;
}
