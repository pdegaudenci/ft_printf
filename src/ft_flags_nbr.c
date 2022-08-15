/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdegaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:57:02 by pdegaude          #+#    #+#             */
/*   Updated: 2022/08/10 21:31:58 by pdegaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_fill(t_print *tab, char *fill, int cont)
{
	if (fill == NULL)
		return ;
	if (tab->sign && tab->minus == 0)
		cont++;
	fill[cont--] = '\0';
	if (cont >= 0 && tab->sign < 0 && tab->zero == 0 && tab->minus == 0)
		fill[cont--] = '-';
	while (cont >= 0)
	{
		if (cont == 0 && tab->sign < 0 && tab->minus == 0 && tab->zero != 0)
		{
			fill[cont] = '-';
			break ;
		}
		else if (tab->zero == 1 && tab->minus == 0)
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
	if (tab->minus == -1)
		tab->minus = 1;
	if (tab->minus > 0)
	{
		tab->zero = 0;
		return (ft_strjoin((const char *)str, (const char *)fill));
	}
	else
		return (ft_strjoin((const char *)fill, (const char *)str));
}

void	ft_apply_prec(t_print *tab, char *str)
{
	if (tab->pnt == 1)
	{
		if (tab->prc >= (int)ft_strlen(str) || tab->wdt - tab->prc > 0)
		{
			if ((tab->minus == 1 && tab->wdt < (int)ft_strlen(str))
				|| tab->pnt == 1)
				tab->minus = 0;
			tab->zero = 1;
			tab->wdt = tab->prc;
			if (str[0] == '-')
				tab->sign = -1;
			if (tab->sign < 0)
				tab->wdt++;
		}
		else
		{
			tab->wdt = ft_strlen(str);
			if (tab->sign < 0)
				tab->wdt++;
		}
	}
}

char	*ft_applyflags_nbr(char *str_w, char *fill, t_print *tab, char *str)
{
	int		cont;
	char	*temp;

	cont = (int)ft_strlen(str);
	ft_apply_prec(tab, str);
	cont = tab->wdt - cont;
	str_w = ft_strnbr(tab, str);
	if (cont < 0 && tab->sign < 0 && tab->limit != 1)
		cont = 0;
	if (cont > 0 || (cont == 0 && tab->sign < 0))
		fill = (char *)malloc(sizeof(char) * (cont + 1));
	ft_fill(tab, fill, cont);
	if (fill != NULL)
	{
		temp = ft_apply_align(fill, str_w, tab);
		free(fill);
	}
	else
		temp = ft_strdup(str_w);
	free(str);
	free(str_w);
	return (temp);
}

char	*ft_apply_width(char *str, t_print *tab)
{
	int		wdt;
	int		dash;

	dash = tab->minus;
	wdt = tab->wdt;
	return (ft_flags_bonus(str, tab, dash, wdt));
}
