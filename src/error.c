#include "pipex.h"

void no_path(char **cmd_argv, char exit_code)
{
    ft_putstr_fd(cmd_argv[0], 2);
    ft_putstr_fd(": command not found\n", 2);
    cleanup_and_exit(cmd_argv, NULL, exit_code);
}
void bad_pipe(char *msg)
{
    perror(msg);
    return(1);
}
