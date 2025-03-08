// int execvpe(const char *file, char *const argv[], char *const envp[]);
#define _GNU_SOURCE
#include <unistd.h>

#include "shell.h"
#include "job.h"

int main()
{
    init_shell();

    return 0;
}
