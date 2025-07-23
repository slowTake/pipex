/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_fts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:19:15 by pnurmi            #+#    #+#             */
/*   Updated: 2025/07/23 11:38:17 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**cmd_parse(char *cmd_str)
{
	char	**args;
	int		i;

	i = 0;
	if (!cmd_str)
		return (NULL);
	while ((cmd_str[i] && cmd_str[i] == ' ') || cmd_str[i] == '\t')
		i++;
	if (cmd_str[i] == '\0')
		return (NULL);
	args = ft_split(cmd_str, ' ');
	if (!args || !args[0])
	{
		cmd_freeargs(args);
		return (NULL);
	}
	return (args);
}

void	cmd_freeargs(char **args)
{
	int	i;

	i = 0;
	if (!args)
		return ;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	cleanup_and_exit(char **cmd_args, char *cmd_path, int exit_code)
{
	if (cmd_args)
		cmd_freeargs(cmd_args);
	if (cmd_path)
		free(cmd_path);
	exit(exit_code);
}

pid_t	cmd_fork(int pipefd[2])
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		perror("fork");
		exit(1);
	}
	return (pid);
}

void	cmd_error_msg(char *msg, int exit_code)
{
	ft_putstr_fd(msg, 2);
	exit(exit_code);
}
