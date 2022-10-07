/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:57:10 by vfranco-          #+#    #+#             */
/*   Updated: 2022/07/11 10:30:44 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

int	get_files_fds(int argc, char **argv, int fd[][2])
{
	fd[0][0] = open(argv[1], O_RDONLY);
	if (fd[0][0] == -1)
		perror(argv[1]);
	fd[0][1] = open(argv[4], O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if (fd[0][1] == -1)
		perror(argv[argc - 1]);
	return (1);
}

int	open_pipes(int argc, char **argv, int fd[][2])
{
	int	i;

	get_files_fds(argc, argv, fd);
	i = 1;
	while (i < 2)
	{
		if (pipe(fd[i]) == -1)
		{
			close_pipes_until(fd, i);
			perror("");
			return (-1);
		}
		i++;
	}
	return (0);
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
