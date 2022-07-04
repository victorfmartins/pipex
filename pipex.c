/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:57:10 by vfranco-          #+#    #+#             */
/*   Updated: 2022/07/04 11:47:16 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

void	close_pipes_until(int fd[][2], int n) //lembrar de tirar o process_idx
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

int	get_files_fds(char **argv, int fd[][2], int qtd)
{
	int	here_doc;

	here_doc = ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0; // +1 for LIMITER
	fd[0][0] = open(argv[1 + here_doc], O_RDONLY);
	if (fd[0][0] == -1)
		return (-1);
	if (here_doc)
		fd[0][1] = open(argv[qtd + 2 + here_doc], O_APPEND | O_CREAT | O_WRONLY , 0664);
	else
		fd[0][1] = open(argv[qtd + 2 + here_doc], O_TRUNC | O_CREAT | O_WRONLY , 0644);
	if (fd[0][1] == -1)
	{
		close(fd[0][0]);
		return (-1);
	}
	return (1);
}

int	open_pipes(char **argv, int fd[][2], int qtd)
{
	int	i;

	if (get_files_fds(argv, fd, qtd) == -1)
		return (-1);
	i = 1;
	while (i < qtd)
	{
		if (pipe(fd[i]) == -1)
		{
			close_pipes_until(fd, i);
			return (-1);
		}
		i++;
	}
	return (0);
}

void manage_pipes(int fd[][2], int process_idx, int pipes_qtd)
{
	int	i;

	i = 0;
	while (i < pipes_qtd)
	{
		if ((process_idx != 0 && i == process_idx) || (process_idx == 0 && i == 0))
			dup2(fd[i][0], STDIN_FILENO);
		if (i == process_idx + 1 || (process_idx == pipes_qtd - 1 && i == 0))
			dup2(fd[i][1], STDOUT_FILENO);
		i++;
	}
	close_pipes_until(fd, pipes_qtd);
	return ;
}

char	**get_cmd_args(char *argv)
{
	char	**args;

	args = ft_split(argv, ' ');
	return (args);
}

int	enter_process_op(int fd[][2], int process_idx, int process_qtd, char **argv, char **envp)
{
	char	**args;
	char	*cmd;
	int		here_doc;
	
	manage_pipes(fd, process_idx, process_qtd);
	here_doc = ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0; // +1 for LIMITER
	args = get_cmd_args(argv[process_idx + 2 + here_doc]); // pode ser +3 (4) se tiver "here_doc"
	cmd = ft_strjoin("/usr/bin/", args[0]);
	execve(cmd, args, envp);
	// exit(child_error(args, cmd));
	return (1);
}

void	wait_all_child_finish(int id[], int process_qtd)
{
	int	i;

	i = 0;
	while (i < process_qtd)
	{
		waitpid(id[i], NULL, 0);
		i++;
	}
	return ;
}

int	pipex(int process_qtd, char **argv, char **envp)
{
	int	fd[process_qtd][2];
	int	id[process_qtd];
	int	i;

	if (open_pipes(argv, fd, process_qtd) == -1)
		return (-1);
	i = 0;
	while (i < process_qtd)
	{
		id[i] = fork();
		if (id[i] == -1)
		{
			close_pipes_until(fd, process_qtd);
			return (-1);
		}
		if (id[i] == 0)
			enter_process_op(fd, i, process_qtd, argv, envp);
		i++;
	}
	close_pipes_until(fd, process_qtd);
	wait_all_child_finish(id, process_qtd);
	return (1);
}

int	get_command_qtd(int argc, char **argv)
{
	if (argc < 5)
		return (-1);
	if (argc > 5 && ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0)
		return (argc - 4);
	else
		return (argc - 3);
}

int	main(int argc, char **argv, char **envp)
{
	int	process_qtd;
	// char	**args;
	// int	i;

	process_qtd = get_command_qtd(argc, argv);
	// printf("%d\n", process_qtd);
	if (process_qtd == -1)
		return (-1);
	// if (!is_valid_commands())
		// return err
	if (pipex(process_qtd, argv, envp) == -1)
		return (-1);
	// args = get_cmd_args(argv[0 + 2]);
	// i = 0;
	// while (args && args[i])
	// {
	// 	printf("%s ", args[i]);
	// 	i++;
	// }
	// printf("\n");
	write(1, "Success\n", 8);
	return (0);
}