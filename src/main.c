// int execvpe(const char *file, char *const argv[], char *const envp[]);
#define _GNU_SOURCE
#include <unistd.h>

#include "shell.h"
#include "job.h"

int main()
{
    init_shell();

    clearenv();
    setenv("PATH", "/bin:/usr/bin", 1);
    printf("PATH=%s\n", getenv("PATH"));

    char *argv[] = { "echo", "Hello, World!", NULL };
    execvp(argv[0], argv);

    perror("execvp");

    return 0;
}
