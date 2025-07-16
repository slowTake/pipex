#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h> //wait
# include <unistd.h>

int		cmd_findpath(char *envp[]);
char	**cmd_split(char *cmd_path);
char	*cmd_check(char *envp[], char *cmd);
char	*create_full_path(char *path, char *cmd);
char	**cmd_parse(char *cmd_str);
void	kid_one(char *argv[], char *envp[], int *pipefd);
void	kid_two(char *argv[], char *envp[], int *pipefd);
void	cleanup_and_exit(char **cmd_args, char *cmd_path, int exit_code);

#endif