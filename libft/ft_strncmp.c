/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdegaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:41:43 by pdegaude          #+#    #+#             */
/*   Updated: 2022/06/22 16:59:54 by pdegaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			cont;
	unsigned char	*src;
	unsigned char	*dst;

	src = (unsigned char *)s1;
	dst = (unsigned char *)s2;
	cont = 0;
	if (n == 0)
	{
		return (0);
	}
	while ((src[cont] != '\0' || dst[cont] != '\0')
		&& cont < n)
	{
		if (src[cont] > dst[cont])
		{
			return (src[cont] - dst[cont]);
		}
		else if (src[cont] < dst[cont])
		{
			return (src[cont] - dst[cont]);
		}
		cont++;
	}
	return (0);
}
