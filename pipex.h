/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 18:04:09 by vfranco-          #+#    #+#             */
/*   Updated: 2022/07/05 10:54:55 by vfranco-         ###   ########.fr       */
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

int		main(int argc, char **argv, char **envp);
char	**ft_split_pass(char const *s, char c, char l);

#endif