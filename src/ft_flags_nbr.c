/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdegaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:57:02 by pdegaude          #+#    #+#             */
/*   Updated: 2022/07/31 15:38:00 by pdegaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_fill(t_print *tab, char *fill, int cont)
{
	if (fill == NULL)
		return ;
	if (tab->sign && tab->dash == 0)
		cont++;
	fill[cont--] = '\0';
	if (cont != 0 && tab->sign < 0 && tab->zero == 0 && tab->dash == 0)
		fill[cont--] = '-';
	while (cont >= 0)
	{
		if (cont == 0 && tab->sign < 0 && tab->dash == 0 && tab->zero != 0)
		{
			fill[cont] = '-';
			break ;
		}
		else if (tab->zero == 1 && tab->dash == 0)
		{
			fill[cont] = '0';
		}
		else
		{
			fill[cont] = ' ';
		}
		cont--;
	}
}

char	*ft_apply_align(char *fill, char *str, t_print *tab)
{
	if (tab->dash > 0)
	{
		tab->zero = 0;
		return (ft_strjoin((const char *)str, (const char *)fill));
	}
	else
		return (ft_strjoin((const char *)fill, (const char *)str));
}

void	ft_apply_prec(t_print *tab)
{
	if (tab->pnt == 1)
	{
		tab->zero = 1;
		tab->wdt = tab->prc;
		if (tab->sign < 0)
			tab->wdt++;
	}
}

char	*ft_applyflags_nbr(char *str_w, char *fill, t_print *tab, char *str)
{
	int		cont;
	char	*temp;

	temp = NULL;
	cont = (int)ft_strlen(str);
	ft_apply_prec(tab);
	cont = tab->wdt - cont;
	if (cont > 0 || (cont == 0 && tab->sign < 0))
		fill = (char *)malloc(sizeof(char) * (cont + 1));
	ft_fill(tab, fill, cont);
	if (tab->sign < 0 && tab->dash == 0)
		str_w = ft_substr((char const *) str, 1, ft_strlen(str));
	else
		str_w = ft_substr((char const *) str, 0, ft_strlen(str));
	if (fill != NULL)
	{
		temp = ft_apply_align(fill, str_w, tab);
		free (fill);
	}
	else
		temp = ft_strdup(str_w);
	free(str);
	free(str_w);
	return (temp);
}

char	*ft_apply_width(char *str, t_print *tab)
{
	char	*str_w;
	char	*fill;

	str_w = NULL;
	fill = NULL;
	return (ft_applyflags_nbr(str_w, fill, tab, str));
}
