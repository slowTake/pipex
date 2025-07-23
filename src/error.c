/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 09:31:40 by pnurmi            #+#    #+#             */
/*   Updated: 2025/07/23 10:24:38 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	no_path(char **cmd_argv, int exit_code)
{
	ft_putstr_fd(cmd_argv[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	cleanup_and_exit(cmd_argv, NULL, exit_code);
}

void	bad_pipe(char *msg)
{
	perror(msg);
	exit(1);
}

void	no_infile(char *filename, char **cmd_argv, char *cmd_paths,
		int exit_code)
{
	perror(filename);
	cleanup_and_exit(cmd_argv, cmd_paths, exit_code);
}

void	bad_dup(char *msg, int exit_code)
{
	perror(msg);
	cleanup_and_exit(NULL, NULL, exit_code);
}
