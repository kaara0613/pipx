/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_from_infile.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:25:20 by kaara             #+#    #+#             */
/*   Updated: 2025/01/21 15:25:20 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_from_infile(t_pipex *pipex, char *const *envp)
{
	if (pipe(pipex->pipe_fd) == -1)
	{
		perror("pipe return -1.");
		exit(EXIT_FAILURE);
	}
	pipex->infile_fd = open(pipex->infile_name, O_RDONLY);
	if (dup2(pipex->infile_fd, STDIN_FILENO) == -1)
	{
		perror("dup2 return -1.");
		exit(EXIT_FAILURE);
	}
	if (dup2(STDOUT_FILENO, pipex->pipe_fd[1]) == -1)
	{
		perror("dup2 return -1.");
		exit(EXIT_FAILURE);
	}
	//
	int i = 0;
	printf("%s\n", pipex->full_path);
	while (pipex->execve_argv[i] != NULL)
		printf("%s\n", pipex->execve_argv[i++]);
	//
	close(pipex->infile_fd);
	execve(pipex->full_path, pipex->execve_argv, envp);
	perror("execve failed");
	exit(EXIT_FAILURE);
}
