/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdegaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:40:27 by pdegaude          #+#    #+#             */
/*   Updated: 2022/07/04 11:48:30 by pdegaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		cont;
	char	*str;

	cont = 0;
	str = 0;
	while (s[cont])
	{
		if (s[cont] == (char )c) // Casteo a char 
			str = (char *)(s + cont);
		cont++;
	}
	if (s[cont] == c)
		str = (char *)(s + cont);
	return (str);
}
