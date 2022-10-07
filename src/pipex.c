/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:57:10 by vfranco-          #+#    #+#             */
/*   Updated: 2022/10/07 16:13:01 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	pipex(int argc, char **argv, char **envp, int *status)
{
	int	fd[2][2];
	int	id[2];
	int	i;

	if (open_pipes(argc, argv, fd) == -1)
		return (-1);
	i = 0;
	while (i < 2)
	{
		id[i] = fork();
		if (id[i] == -1)
		{
			close_pipes_until(fd, 2);
			perror("");
			return (-2);
		}
		if (id[i] == 0)
			enter_process_op(fd, i, argv, envp);
		i++;
	}
	close_pipes_until(fd, 2);
	wait_all_child_finish(id, status);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	int	status;

	if (argc != 5)
	{
		ft_putstr_fd("Input error: not enough arguments\n", 1);
		return (EXIT_FAILURE);
	}
	if (pipex(argc, argv, envp, &status) == -1)
		return (EXIT_FAILURE);
	exit(WEXITSTATUS(status));
}
