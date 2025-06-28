/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 10:43:38 by pnurmi            #+#    #+#             */
/*   Updated: 2025/06/28 16:23:40 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h> //wait
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int fd[2];
	int pid1;
	int pid2;

	if (pipe(fd) == -1)
	{
		perror("pipe failed");
		return (1);
	}
	pid1 = fork();

	if (pid1 < 0)
	{
		perror("bad fork");
		close(fd[0]);
		close(fd[1]);
		return (2);
	}
	if (pid1 == 0) // child process
	{
		dup2(fd[1], STDIN_FILENO); // replace with address of outfile
		close(fd[0]);
		close(fd[1]);
		execlp("ping", "ping", "-c", "5", "google.com", NULL);
	}

	pid2 = fork(); // child 2 process
	if (pid2 < 0)
	{
		return (3);
	}
	if (pid2 == 0)
	{
		dup2(fd[0], STDIN_FILENO); // replace with address of outfile
		execlp("grep", "grep", "rtt", NULL);
	}
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}