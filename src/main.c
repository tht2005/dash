#include <string.h>

#include "shell.h"
#include "job.h"

#include "io.h"

int main()
{
    init_shell();
    loop_shell();

    return 0;
}
