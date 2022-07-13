/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdegaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:14:13 by pdegaude          #+#    #+#             */
/*   Updated: 2022/06/22 17:14:19 by pdegaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	cont;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	/*if (len > ft_strlen(s)) // MODIFICAR ORIGINAL CON ESTA CONDICION
		len = ft_strlen(s); --> No pasa mulinette*/
	str = malloc(sizeof(char) * (len + 1));
	cont = 0;
	if (!str)
		return (0);
	while (cont < len)
	{
		str[cont] = *(s + start + cont);
		cont++;
	}
	str[cont] = '\0';
	return (str);
}
