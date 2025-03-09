#include "shell.h"

pid_t shell_pgid;
struct termios shell_tmodes;
int shell_terminal;
int shell_is_interactive;
int shell_is_continue;

void
init_shell()
{
    shell_terminal = STDIN_FILENO;
    shell_is_interactive = isatty(shell_terminal);
    shell_is_continue = 1;

    if(shell_is_interactive)
    {
        while(tcgetpgrp (shell_terminal) != (shell_pgid = getpgrp ()))
            kill(- shell_pgid, SIGTTIN);

        signal(SIGINT, SIG_IGN);
        signal(SIGQUIT, SIG_IGN);
        signal(SIGTSTP, SIG_IGN);
        signal(SIGTTIN, SIG_IGN);
        signal(SIGTTOU, SIG_IGN);
        signal(SIGCHLD, SIG_IGN);

        shell_pgid = getpid ();
        if (setpgid (shell_pgid, shell_pgid) < 0) {
            perror ("Couldn't put the shell in its own process group");
            exit(1);
        }

        tcsetpgrp (shell_terminal, shell_pgid);
        
        tcgetattr (shell_terminal, &shell_tmodes);
    }
}

void
loop_shell()
{
    printf ("debug: %d\n", COMMAND_BEGIN);
    printf ("debug: %d\n", COMMAND_END);
    printf ("debug: %d\n", ARITHMETIC_BEGIN);
    printf ("debug: %d\n", ARITHMETIC_END);

    while(shell_is_continue) {
        printf("dash> $ ");

        char *cmd = dfgets(stdin);

        printf("cmd = \"%s\"\n", cmd);

        //temporary for gracefully exit
        if(strcmp(cmd, "exit") == 0) {
            shell_is_continue = 0;
        }
        else {
            token tk;

            init_interpreter (cmd);
            while ((tk = next_token ()).type != ENDFILE)
            {
                printf ("debug: %d %s\n", tk.type, tk.str);
            }
        }

        freebuf();
    }
}
