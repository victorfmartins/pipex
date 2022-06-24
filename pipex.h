/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 18:04:09 by vfranco-          #+#    #+#             */
/*   Updated: 2022/06/24 18:21:23 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PIPEX_H
# define PIPEX_H
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>

# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 600

# define PIPEX_ERROR -1

typedef struct s_struc
{
	int		i;
}	t_struc;

int		main(int argc, char **argv);
#endif