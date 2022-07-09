/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdegaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:05:16 by pdegaude          #+#    #+#             */
/*   Updated: 2022/06/22 16:58:26 by pdegaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		cont;

	cont = 0;
	if (!s || (!s && !f))
		return (0);
	else if (!f)
		return ((char *)s);
	str = ft_strdup(s);
	if (!str)
	{
		str = NULL;
		return (str);
	}
	while (s[cont])
	{
		str[cont] = (*f)(cont, s[cont]);
		cont++;
	}
	return (str);
}
