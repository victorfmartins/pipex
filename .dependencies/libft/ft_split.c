/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 14:20:25 by vfranco-          #+#    #+#             */
/*   Updated: 2022/07/05 12:21:08 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrimc(char const *s, char c);

static void	ft_matrix(char **arr, char *cpy, char c, int counti)
{
	int	size;
	int	countj;
	int	i;

	countj = 0;
	size = 0;
	i = 0;
	while (i < counti)
	{
		if (ft_strchr(cpy + size, c))
			countj = ft_strchr(cpy + size, c) - (cpy + size);
		else
			countj = ft_strlen(cpy + size);
		arr[i] = malloc(sizeof(char) * (countj + 1));
		ft_strlcpy(arr[i], cpy + size, countj + 1);
		size += countj;
		while (cpy[size] && cpy[size] == c)
			size++;
		i++;
	}
	arr[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		counti;
	char	*cpy;
	char	**arr;

	cpy = ft_strtrimc(s, c);
	if (!cpy)
		return (NULL);
	counti = (ft_strncmp(cpy, "", 1) != 0);
	i = 0;
	while (cpy[i])
	{
		if (cpy[i] == c)
		{
			while (cpy[i + 1] == c)
				i++;
			counti++;
		}
		i++;
	}
	arr = malloc(sizeof(char *) * (counti + 1));
	if (arr)
		ft_matrix(arr, cpy, c, counti);
	free(cpy);
	return (arr);
}
