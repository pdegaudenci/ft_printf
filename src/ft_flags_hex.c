/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdegaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:54:17 by pdegaude          #+#    #+#             */
/*   Updated: 2022/08/10 20:36:48 by pdegaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_eval_wdt(t_print *tab, unsigned int num, char format)
{
	int	cont;

	cont = 0;
	if (tab->minus == 1)
	{
		tab->zero = 0;
		if (tab->sharp == 1)
			cont += ft_applysharp(format);
		ft_put_hex(num, format, tab);
		return (ft_put_wdt(tab, num));
	}
	if (tab->sharp == 1)
		cont += ft_applysharp(format);
	cont += ft_put_wdt(tab, num);
	ft_put_hex(num, format, tab);
	return (cont);
}

int	ft_prec_hex(unsigned int num, char format, t_print *tab, int cont)
{
	char	*num_str;
	char	*num_wdt;

	num_str = ft_itoa_hex(num, format);
	num_wdt = ft_apply_width(num_str, tab);
	num_wdt = ft_apply_bonus(num_wdt, format, tab);
	cont += ft_printstr(num_wdt);
	free(num_wdt);
	return (cont);
}

int	ft_put_wdt(t_print *tab, int num)
{
	int	cont;

	cont = 0;
	if (num == 0)
	{
		tab->wdt--;
		cont++;
	}
	if (tab->wdt - ft_hex_len(num) > 0)
	{
		tab->wdt -= ft_hex_len(num);
		while (tab->wdt > 0)
		{
			if (tab->zero > 0 && tab->minus == 0)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			tab->wdt--;
			cont++;
		}
	}
	return (cont);
}
