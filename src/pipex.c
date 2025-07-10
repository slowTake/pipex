/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 10:43:38 by pnurmi            #+#    #+#             */
/*   Updated: 2025/07/10 10:45:16 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	kid_one(char *argv[], char *envp[], int *pipefd)
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
	{
		perror("infile");
		exit(1);
	}
	dup2(infile, STDIN_FILENO);
	close(infile);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	close(pipefd[1]);
	execve(cmd_findpath, argv[2], envp);
}
void	kid_two(char *argv[], char *envp[], int *pipefd)
{
	int	outfile;

	outfile = open(argv[4], O_RDONLY);
	if (outfile == -1)
	{
		perror("outfile");
		exit(1);
	}
	dup2(outfile, STDIN_FILENO);
	close(outfile);
	dup2(pipefd[0], STDOUT_FILENO);
	close(pipefd[0]);
	close(pipefd[1]);
	execve(cmd_findpath, argv[3], envp);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(pipefd) < 0)
	{
		perror("pipe fail");
		return (-1);
	}
	pid1 = fork();
	if (pid1 == 0)
		kid_one(argv[2], envp, pipefd[0]);
	pid2 = fork();
	if (pid2 == 0)
		kid_two(argv[3], envp, pipefd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
