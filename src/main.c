#include "cpp_string.h"

#include <string.h>
#include "shell.h"
#include "job.h"

#include "io.h"

int main (int argc, char **argv)
{
    if (argc > 2) {
        fprintf(stderr, "Invalid number of arguments (%d)\n", argc - 1);
        exit(1);
    }

    // work as a interpreter
    if (argc == 2) {
        freopen (argv[1], "r", stdin);
    }

    init_shell ();
    loop_shell ();

    return 0;
}
