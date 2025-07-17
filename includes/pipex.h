#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

char	*cmd_findpath(char *envp[]);
char	*create_full_path(char *directory, char *cmd);
char	*check_absolute_path(char *cmd);
char	*cmd_path_search(char **paths, char *cmd);
char	*cmd_check(char *envp[], char *cmd);
void	cmd_freeargs(char **args);
char	**cmd_parse(char *cmd_str);
void	kid_one(char *argv[], char *envp[], int *pipefd);
void	cleanup_and_exit(char **cmd_args, char *cmd_path, int exit_code);
void	kid_two(char *argv[], char *envp[], int *pipefd);
void	cmd_freeargs(char **args);
pid_t	cmd_fork(int pipefd[2]);
void	cmd_error_msg(char *msg, int exit_code);

#endif