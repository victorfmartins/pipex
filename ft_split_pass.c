/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pass.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:38:05 by vfranco-          #+#    #+#             */
/*   Updated: 2022/07/10 16:46:31 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

static size_t	count_words(char *str, char c, char l)
{
	size_t	i;
	size_t	words_qtd;

	words_qtd = (ft_strncmp(str, "", 1) != 0);
	i = 0;
	while (str[i])
	{
		if (str[i] == l)
		{
			while (str[i + 1] && str[i + 1] != l)
				i++;
			i++;
		}
		if (str[i] == c)
		{
			while (str[i + 1] == c)
				i++;
			words_qtd++;
		}
		i++;
	}
	return (words_qtd);
}

static size_t	word_lenght(const char *str, char c, char l)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == c || str[i] == '\0')
			return (i);
		if (str[i] == l)
		{
			while (str[i + 1] && str[i + 1] != l)
				i++;
			i++;
		}
		i++;
	}
	return (i);
}

static void	free_until(char **arr, int n)
{
	while (n-- >= 0)
		free(arr[n]);
	return ;
}

static void	build_arr(char ***arr, char *cpy, char c, char l)
{
	int		words_qtd;
	int		word_len;
	int		word;

	words_qtd = count_words(cpy, c, l);
	(*arr) = malloc(sizeof(char *) * (words_qtd + 1));
	if (!(*arr))
		return ;
	word_len = 0;
	word = 0;
	while (word < words_qtd)
	{
		word_len = word_lenght(cpy, c, l);
		(*arr)[word] = malloc(sizeof(char) * (word_len + 1));
		if (!(*arr)[word])
			return (free_until((*arr), word - 1));
		ft_strlcpy((*arr)[word], cpy, word_len + 1);
		cpy = cpy + word_len;
		while (cpy && *cpy == c)
			cpy++;
		word++;
	}
	(*arr)[word] = NULL;
	return ;
}

char	**ft_split_pass(char const *s, char c, char l)
{
	char	*cpy;
	char	**arr;

	cpy = ft_strtrimc(s, c);
	if (!cpy || c == l)
		return (NULL);
	build_arr(&arr, cpy, c, l);
	free(cpy);
	return (arr);
}

// int	main(int argc, char **argv, char **envp)
// {
// 	char	**str;
// 	int		i;

// 	str = ft_split_pass(argv[1], ' ', '\'');
// 	i = 0;
// 	while (str && str[i])
// 	{
// 		printf("Word[%d]: %s\n", i, str[i]);
// 		i++;
// 	}
// 	return (0);
// }
