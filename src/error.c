/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 09:31:40 by pnurmi            #+#    #+#             */
/*   Updated: 2025/07/22 10:13:49 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	no_path(char **cmd_argv, char exit_code)
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

void	no_infile(char **cmd_argv, char *cmd_paths, char exit_code)
{
	ft_putstr_fd(cmd_argv[0], 2);
	ft_putstr_fd(": file not found\n", 2);
	cleanup_and_exit(cmd_argv, cmd_paths, exit_code);
}
