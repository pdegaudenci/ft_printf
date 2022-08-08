/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdegaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:49:03 by pdegaude          #+#    #+#             */
/*   Updated: 2022/08/08 17:28:06 by pdegaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_fill_str(char *fill, int size)
{
	int	cont;

	cont = 0;
	while (size > 0)
	{
		fill[cont++] = ' ';
		size--;
	}
	fill[cont] = '\0';
}

char	*ft_apply_width_str(char *str, t_print *tab)
{
	int		cont;
	char	*str_w;
	char	*fill;
	char	*temp;

	cont = (int)ft_strlen(str);
	str_w = NULL;
	cont = tab->wdt - cont;
	fill = (char *)malloc (sizeof(char) * (cont + 1));
	ft_fill_str(fill, cont);
	if (tab->pnt > 0)
		str_w = ft_substr((char const *)str, 0, tab->prc);
	else
		str_w = ft_substr((char const *)str, 0, ft_strlen(str));
	if (tab->dash > 0)
		temp = ft_strjoin((const char *)str_w, (const char *)fill);
	else
		temp = ft_strjoin((const char *)fill, (const char *)str_w);
	free(fill);
	free(str_w);
	return (temp);
}
