/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdegaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:36:16 by pdegaude          #+#    #+#             */
/*   Updated: 2022/06/17 21:36:33 by pdegaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	cont;
	size_t			size;

	size = dstsize;
	cont = 0;
	if (size == 0)
	{
		return (ft_strlen(src));
	}
	while ((src[cont] != '\0') && (cont < size -1))
	{
		dst[cont] = src[cont];
		cont++;
	}
	dst[cont] = '\0';
	return (ft_strlen(src));
}
