/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdegaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:39:37 by pdegaude          #+#    #+#             */
/*   Updated: 2022/07/26 18:05:58 by pdegaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	cont;

	cont = 0;
	while (*(s + cont))
	{
		if (*(s + cont) == (char )c)
			return ((char *)s + cont);
		cont++;
	}
	if (*(s + cont) == (char)c)
		return ((char *)s + cont);
	return (0);
}
