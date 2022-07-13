/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdegaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:09:06 by pdegaude          #+#    #+#             */
/*   Updated: 2022/07/05 12:13:14 by pdegaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char *str, char c)
{
	int	i;
	int	cont;
	int	first_word;

	i = 0;
	cont = 0;
	first_word = 0;
	while (str[i] == c && str[i])
		i++;
	while (str[i])
	{
		if (str[i] != c && str[i])
			first_word = 1;
		if (str[i] == c)
		{
			while (str[i] == c && str[i])
				i++;
			if (str[i])
				cont++;
		}
		else
			i++;
	}
	return (cont + first_word);
}

static	char	*ft_insert_word(char *str, char c)
{
	int		i;
	char	*arr;

	i = 0;
	arr = 0;
	while (str[i] && str[i] != c)
		i++;
	arr = (char *)malloc(sizeof(char) * (i + 1));
	if (!arr)
		return (NULL);
	ft_strlcpy(arr, str, i + 1);
	return (arr);
}

static void	ft_freemem(char **array, int i)
{
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		words;
	char	**array;

	i = -1;
	if (!s)
		return (NULL);
	words = ft_count_words((char *)s, c);
	array = malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);
	while (++i < words)
	{
		while (s[0] == c)
			s++;
		array[i] = ft_insert_word((char *)s, c);
		if (!array[i])
		{
			ft_freemem(array, i);
			return (NULL);
		}
		s += ft_strlen(array[i]);
	}
	array[i] = 0; 
	return (array);
}
