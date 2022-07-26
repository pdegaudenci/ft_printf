/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdegaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:54:17 by pdegaude          #+#    #+#             */
/*   Updated: 2022/07/26 13:56:20 by pdegaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

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
			if (tab->zero > 0 && tab->dash == 0)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			tab->wdt--;
			cont++;
		}
	}
	return (cont);
}
