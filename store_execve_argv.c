/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_execve_argv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:12:27 by kaara             #+#    #+#             */
/*   Updated: 2025/01/22 17:09:56 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**store_execve_argv(t_pipex *pipex, char **cmd)
{
	int		i;
	int		execve_argc;
	char	**execve_argv;

	execve_argc = 0;
	while (cmd[i] != NULL)
		execve_argc++;
	execve_argv[0] = allocation_and_cpy(pipex->full_path);
	i = 1;
	while (cmd[i] != NULL)
	{
		execve_argv[i] = allocation_and_cpy(cmd[i]);
		i++;
	}
	execve_argv[i] = NULL;
	return (execve_argv);
}
