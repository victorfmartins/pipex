/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:12:43 by vfranco-          #+#    #+#             */
/*   Updated: 2022/07/04 15:14:05 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strtrimc(char const *s, char c)
{
	char	*set;
	char	*strtrimed;

	set = malloc(sizeof(char) * 2);
	if (!set)
		return (NULL);
	*set = c;
	*(set + 1) = '\0';
	strtrimed = ft_strtrim(s, set);
	free(set);
	return (strtrimed);
}
