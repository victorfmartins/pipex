/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:01:50 by vfranco-          #+#    #+#             */
/*   Updated: 2022/10/07 16:32:20 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/processes.h"

static void	free_args(char ***args, char **cmd)
{
	int	i;

	i = 0;
	while ((*args)[i])
		free((*args)[i++]);
	free(*args);
	free(*cmd);
}

int	enter_process_op(int fd[][2], int process_idx, char **argv, char **envp)
{
	char	**args;
	char	*cmd;

	manage_pipes(fd, process_idx, 2);
	args = ft_split_pass(argv[process_idx + 2], ' ', '\'');
	cmd = ft_strjoin("/usr/bin/", args[0]);
	execve(cmd, args, envp);
	exit(process_error(&args, &cmd));
	return (1);
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
