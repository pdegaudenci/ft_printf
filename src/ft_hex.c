/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdegaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:53:35 by pdegaude          #+#    #+#             */
/*   Updated: 2022/07/26 16:17:43 by pdegaude         ###   ########.fr       */
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

void	ft_put_hex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, format);
		ft_put_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_print_char((num + '0'));
		else if (num >= 0)
		{
			if (format == 'x')
				ft_print_char(num - 10 + 'a');
			if (format == 'X')
				ft_print_char(num - 10 + 'A');
		}
	}
}

static int	ft_eval_wdt(t_print *tab, unsigned int num, char format)
{
	int	cont;

	cont = 0;
	if (tab->dash == 1)
	{
		tab->zero = 0;
		ft_put_hex(num, format);
		cont += ft_put_wdt(tab, num);
	}
	else
	{
		cont += ft_put_wdt(tab, num);
		ft_put_hex(num, format);
	}
	return (cont);
}

int	ft_print_hex(unsigned int num, const char format, t_print *tab)
{
	int		cont;
	char	*num_str;
	char	*num_wdt;

	cont = 0;
	if (tab->prc == 1)
		tab->pnt = 0;
	if ((num == 0 && (tab->wdt - 1) <= 0) && tab->pnt == 0)
		cont += write(1, "0", 1);
	else if (tab->pnt == 0 || tab->wdt > ft_num_len(num))
	{
		return (cont + ft_eval_wdt(tab, num, format) + ft_hex_len(num));
	}
	else if (tab->pnt == 1)
	{
		num_str = ft_itoa_hex(num, format);
		num_wdt = ft_apply_width(num_str, tab);
		cont += ft_printstr(num_wdt);
		free(num_wdt);
		return (cont);
	}
	return (cont);
}
