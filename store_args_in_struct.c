/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_args_in_struct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:26:55 by kaara             #+#    #+#             */
/*   Updated: 2025/01/21 15:26:55 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	store_args_in_struct(t_pipex *pipex, int argc, char **argv)
{
	pipex->infile_name = allocation_and_cpy(argv[1]);
	if (pipex->infile_name == NULL)
		free_exit(pipex, false);
	pipex->outfile_name = allocation_and_cpy(argv[argc - 1]);
	if (pipex->outfile_name == NULL)
		free_exit(pipex, false);
	pipex->cmdc = argc - 2 - 1;
	pipex->cmdc_i = 0;
	pipex->cmdv = (char ***)malloc(sizeof(char **) * pipex->cmdc);
	if (pipex->cmdv == NULL)
		free_exit(pipex, false);
	while (pipex->cmdc_i <= pipex->cmdc - 1)
	{
		pipex->cmdv[pipex->cmdc_i] = ft_split(argv[pipex->cmdc_i + 1 + 1], ' ');
		if (pipex->cmdv[pipex->cmdc_i] == NULL)
			free_exit(pipex, false);
		pipex->cmdc_i++;
	}
	pipex->cmdv[pipex->cmdc_i] = NULL;
	pipex->cmdc_i = 0;
}
