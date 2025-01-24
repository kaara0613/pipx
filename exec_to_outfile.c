/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_to_outfile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:25:09 by kaara             #+#    #+#             */
/*   Updated: 2025/01/21 15:25:09 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_to_outfile(t_pipex *pipex, char *const *envp)
{
	pipex->outfile_fd = open(pipex->outfile_name, O_WRONLY);
	if (dup2(pipex->pipe_fd[1], STDIN_FILENO) == -1)
	{
		perror("dup2 return -1.");
		exit(EXIT_FAILURE);
	}
	close(pipex->pipe_fd[1]);
	if (pipe(pipex->pipe_fd) == -1)
	{
		perror("pipe return -1.");
		exit(EXIT_FAILURE);
	}
	close(pipex->pipe_fd[0]);
	if (dup2(STDOUT_FILENO, pipex->outfile_fd) == -1)
	{
		perror("dup2 return -1.");
		exit(EXIT_FAILURE);
	}
	execve(pipex->full_path, pipex->execve_argv, envp);
	perror("execve failed");
	exit(EXIT_FAILURE);
}
