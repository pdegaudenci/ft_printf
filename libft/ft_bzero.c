/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdegaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:33:29 by pdegaude          #+#    #+#             */
/*   Updated: 2022/06/21 15:14:38 by pdegaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*dest;
	size_t	cont;

	cont = 0;
	dest = (char *)s;
	while (cont < n)
	{
		dest[cont] = 0;
		cont++;
	}
	s = dest;
}
