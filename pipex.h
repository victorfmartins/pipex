/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 18:04:09 by vfranco-          #+#    #+#             */
/*   Updated: 2022/07/11 09:49:35 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "./.dependencies/libft/libft.h"

int		main(int argc, char **argv, char **envp);
char	**ft_split_pass(char const *s, char c, char l);
void	close_pipes_until(int fd[][2], int n);
void	free_args(char ***args, char **cmd);
int		process_error(char ***args, char **cmd);
void	wait_all_child_finish(int id[], int *status);
void	manage_pipes(int fd[][2], int process_idx, int pipes_qtd);
size_t	count_words(char *str, char c, char l);
size_t	word_lenght(char *str, char c, char l);
void	free_until(char **arr, int n);

#endif