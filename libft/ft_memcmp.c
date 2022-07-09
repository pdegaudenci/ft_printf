/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdegaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:59:51 by pdegaude          #+#    #+#             */
/*   Updated: 2022/06/21 12:28:21 by pdegaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char const	*str1;
	char const	*str2;
	size_t		cont;

	cont = 0;
	str1 = (char const *)s1;
	str2 = (char const *)s2;
	while (cont < n)
	{
		if (str1[cont] != str2[cont])
			return ((unsigned char)str1[cont] - (unsigned char)str2[cont]);
		cont++;
	}
	return (0);
}
