/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 10:43:38 by pnurmi            #+#    #+#             */
/*   Updated: 2025/07/23 11:38:16 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	kid_one(char *argv[], char *envp[], int *pipefd)
{
	int		infile;
	char	*cmd_path;
	char	**cmd_args;

	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		bad_dup("dup2", 1);
	close(pipefd[0]);
	close(pipefd[1]);
	cmd_args = cmd_parse(argv[2]);
	if (!cmd_args)
		cleanup_and_exit(NULL, NULL, 127);
	cmd_path = cmd_check(envp, cmd_args[0]);
	if (!cmd_path)
		no_path(cmd_args, 127);
	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		no_infile(argv[1], cmd_args, cmd_path, 1);
	if (dup2(infile, STDIN_FILENO) == -1)
		bad_dup("dup2", 1);
	close(infile);
	execve(cmd_path, cmd_args, envp);
	perror("execve");
	cleanup_and_exit(cmd_args, cmd_path, 1);
}

void	kid_two(char *argv[], char *envp[], int *pipefd)
{
	int		outfile;
	char	*cmd_path;
	char	**cmd_args;

	if (dup2(pipefd[0], STDIN_FILENO) == -1)
		bad_dup("dup2", 1);
	close(pipefd[0]);
	close(pipefd[1]);
	cmd_args = cmd_parse(argv[3]);
	if (!cmd_args)
		cleanup_and_exit(NULL, NULL, 127);
	cmd_path = cmd_check(envp, cmd_args[0]);
	if (!cmd_path)
		no_path(cmd_args, 127);
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		cleanup_and_exit(cmd_args, cmd_path, 1);
	if (dup2(outfile, STDOUT_FILENO) == -1)
		bad_dup("dup2", 1);
	close(outfile);
	execve(cmd_path, cmd_args, envp);
	perror("execve");
	cleanup_and_exit(cmd_args, cmd_path, 1);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status1;
	int		status2;

	if (argc != 5)
		cmd_error_msg("Usage: ./pipex file1 cmd1 cmd2 file2\n", 1);
	if (pipe(pipefd) < 0)
		bad_pipe("pipe");
	pid1 = cmd_fork(pipefd);
	if (pid1 == 0)
		kid_one(argv, envp, pipefd);
	pid2 = cmd_fork(pipefd);
	if (pid2 == 0)
		kid_two(argv, envp, pipefd);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, &status1, 0);
	waitpid(pid2, &status2, 0);
	if (WIFEXITED(status2))
		return (WEXITSTATUS(status2));
	return (1);
}
