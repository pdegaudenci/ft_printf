/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdegaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:17:10 by pdegaude          #+#    #+#             */
/*   Updated: 2022/06/21 15:19:43 by pdegaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	void	*dst;

	total = size * count;
	/* MODIFICAR PARA QUE SI EN UN CASO PASA UN PARAMETRO = 0
	if (total < count || total < size)
		return (0);-> No pasa mouilnette*/
	dst = malloc(total);
	if (!dst)
		return (0);
	ft_bzero(dst, total);
	return (dst);
}
