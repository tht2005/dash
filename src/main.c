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
    
    char *argv[] = { "echo", "Hello, World\n" };

    process p = { NULL, argv, 0, 0, 0, 0 };

    job j = { NULL, "echo \"Hello, World\"", &p, 0, 0, shell_tmodes, 0, 1, 2 };

    launch_job(&j, 0);

    return 0;
}
