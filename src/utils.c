/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:23:38 by vfranco-          #+#    #+#             */
/*   Updated: 2022/10/07 18:36:50 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	close_pipes_until(int fd[][2], int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		close(fd[i][0]);
		close(fd[i][1]);
		i++;
	}
	return ;
}

void	free_args(char ***args, char **cmd)
{
	int	i;

	i = 0;
	while ((*args)[i])
		free((*args)[i++]);
	free(*args);
	free(*cmd);
}

int	process_error(char ***args, char **cmd)
{
	if (!(*args)[0])
	{
		write(2, "pipex: ", 7);
		ft_putstr_fd("", 2);
		write(2, ": command not found\n", 20);
		free_args(args, cmd);
		return (127);
	}
	else if (access(*cmd, F_OK) == -1)
	{
		write(2, "pipex: ", 7);
		ft_putstr_fd((*args)[0], 2);
		write(2, ": command not found\n", 20);
		free_args(args, cmd);
		return (127);
	}
	else
		perror("pipex");
	free_args(args, cmd);
	return (1);
}

void	wait_all_child_finish(int id[], int *status)
{
	waitpid(id[0], status, 0);
	waitpid(id[1], status, 0);
}

void	manage_pipes(int fd[][2], int process, int pipes_qtd)
{
	int	i;

	i = 0;
	if ((process == 0 && fd[0][0] == -1) || (process == 1 && fd[0][1] == -1))
		exit(1);
	while (i < pipes_qtd)
	{
		if ((process != 0 && i == process) || (process == 0 && i == 0))
			dup2(fd[i][0], STDIN_FILENO);
		if (i == process + 1 || (process == pipes_qtd - 1 && i == 0))
			dup2(fd[i][1], STDOUT_FILENO);
		i++;
	}
	close_pipes_until(fd, pipes_qtd);
	return ;
}
