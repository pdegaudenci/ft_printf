/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdegaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:58:35 by pdegaude          #+#    #+#             */
/*   Updated: 2022/06/22 16:17:03 by pdegaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		cont;
	const char	*str;

	cont = 0;
	str = (const char *)s;
	while (cont < n)
	{
		if (*(unsigned char *)(str + cont) == (unsigned char)c)
			return ((void *)(s + cont));
		cont++;
	}
	return (NULL);
}
