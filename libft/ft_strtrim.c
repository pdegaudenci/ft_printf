/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdegaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:20:01 by pdegaude          #+#    #+#             */
/*   Updated: 2022/06/29 18:04:55 by pdegaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_isset(char c, const char *set)
{
	while (*set)
	{
		if (c == *set++)
			return (1);
	}	
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	char	*start;
	char	*end;

	if (!s1 || !set)
		return (0);
	start = (char *)s1;
	end = start + ft_strlen(s1);
	while (*start && ft_isset(*start, set))
		++start;
	while (start < end && ft_isset(*(end - 1), set))
		--end;
	ret = ft_substr(start, 0, end - start);
	return (ret);
}
/*
int main()
{
	const char *s="   sabes que esta pasando..    ";	
	s=ft_strtrim(s,"  ");
	system("leaks a.out");
	printf("%s\n",s);
	 s = ft_strtrim("   xxxtripouillexx", " x");
	 printf("%s",s);
}
*/