/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 18:04:09 by vfranco-          #+#    #+#             */
/*   Updated: 2022/07/02 11:03:16 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "./.dependencies/libft/libft.h"

# define PIPEX_ERROR -1

// typedef struct s_pipex
// {
// 	int		infile;
// 	int		outfile;
// 	pid_t	**pid;
// 	int		*fd[2];
// }	t_pipex;

int	main(int argc, char **argv, char **envp);

#endif