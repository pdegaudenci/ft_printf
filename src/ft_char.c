/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdegaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:40:36 by pdegaude          #+#    #+#             */
/*   Updated: 2022/07/26 13:40:41 by pdegaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	put_wdt(t_print *tab)
{
	int	cont;

	cont = 0;
	while (tab->wdt - 1 > 0)
	{
		write(1, " ", 1);
		tab->wdt--;
		cont++;
	}
	return (cont);
}

int	ft_printchar_format(int c, t_print *tab)
{
	int	cont;

	cont = 0;
	if (tab->wdt > 0)
	{
		if (tab->dash > 0)
			return (ft_print_char(c) + put_wdt(tab));
		return (put_wdt(tab) + ft_print_char(c));
	}
	return (ft_print_char(c));
}

int	ft_percent(void)
{
	write(1, "%", 1);
	return (1);
}
