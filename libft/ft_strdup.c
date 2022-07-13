/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdegaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:04:13 by pdegaude          #+#    #+#             */
/*   Updated: 2022/06/22 16:52:20 by pdegaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*ft_strcpy(char *cadena1, const char *cadena2)
{
	int	cont;

	cont = 0;
	while (cadena2[cont] != 0)
	{
		cadena1[cont] = cadena2[cont];
		cont++;
	}
	cadena1[cont] = '\0' ;
	return (cadena1);
}

char	*ft_strdup(const char *src)
{
	char	*dst;

	dst = malloc(ft_strlen (src) + 1);
	if (dst == NULL)
		return (NULL);
	ft_strcpy(dst, src);
	return (dst);
}
