/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdegaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:53:35 by pdegaude          #+#    #+#             */
/*   Updated: 2022/08/10 20:36:01 by pdegaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_hex_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_hex(unsigned int num, const char format, t_print *tab)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, format, tab);
		ft_put_hex(num % 16, format, tab);
	}
	else
	{
		if (num <= 9)
			ft_print_char((num + '0'));
		else if (num >= 0)
		{
			if (format == 'x')
			{
				tab->format = 'x';
				ft_print_char(num - 10 + 'a');
			}	
			if (format == 'X')
			{
				tab->format = 'X';
				ft_print_char(num - 10 + 'A');
			}		
		}
	}
}

int	ft_print_hex(unsigned int num, const char format, t_print *tab)
{
	int		cont;
	char	*num_wdt;

	cont = 0;
	if (tab->prc == 1)
		tab->pnt = 0;
	if (num == 0 && (tab->pnt == 1 || tab->pnt == -1)
		&& tab->prc == 0 && tab->wdt == 0)
		return (0);
	if (num == 0 && (tab->pnt == 1 || tab->pnt == -1)
		&& tab->wdt > 0 && tab->prc == 0)
	{
		num_wdt = (char *)malloc((size_t)tab->wdt + 1);
		ft_fill_str(num_wdt, tab->wdt);
		cont += ft_printstr(num_wdt);
		free(num_wdt);
		return (cont);
	}
	if ((num == 0 && (tab->wdt - 1) <= 0) && tab->pnt == 0)
		cont += write(1, "0", 1);
	else if (tab->pnt == 1 || tab->pnt == -1)
		return (ft_prec_hex(num, format, tab, cont));
	else if (tab->pnt == 0 || tab->wdt > ft_num_len(num))
		return (cont + ft_eval_wdt(tab, num, format) + ft_hex_len(num));
	return (cont);
}	
