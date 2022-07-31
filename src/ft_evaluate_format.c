/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evaluate_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdegaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:51:23 by pdegaude          #+#    #+#             */
/*   Updated: 2022/07/31 15:32:45 by pdegaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_evaluate_flags(t_print *tab, const char *str, int *pos)
{
	while (ft_isformat(str[*pos]))
	{
		ft_evaluate_flagsbonus(tab, str, pos);
		if (str[*pos] == '.')
			ft_evaluate_prec(tab, str, pos);
		if (str[*pos] == '-')
		{
			tab->dash = 1;
			*pos = *pos + 1;
		}
		if (str[*pos] == '0' || (str[*pos] >= '0' && str[*pos] <= '9'))
			ft_evaluate_width(tab, str, pos);
	}
	return (ft_format(tab, str[*pos]));
}

void	ft_evaluate_prec(t_print *tab, const char *c, int *pos)
{
	tab->pnt = 1;
	*pos = *pos + 1;
	while (c[*pos] >= '0' && c[*pos] <= '9')
	{
		tab->prc = c[*pos] - '0' + (tab->prc * 10);
		*pos = *pos + 1;
	}
	if (tab->prc == 1)
		tab->pnt = -1;
}

void	ft_evaluate_width(t_print *tab, const char *c, int *pos)
{
	if (c[*pos] == '0')
	{
		if (tab->dash == 0)
			tab->zero = 1;
		*pos = *pos + 1;
	}
	while (c[*pos] >= '0' && c[*pos] <= '9')
	{
		tab->wdt = c[*pos] - '0' + (tab->wdt * 10);
		*pos = *pos + 1;
	}
}

int	ft_isformat(char c)
{
	if (c == 'c' || c == 's')
		return (0);
	if (c == 'p')
		return (0);
	if (c == 'd' || c == 'i' || c == 'u')
		return (0);
	if (c == 'x' || c == 'X')
		return (0);
	if (c == '%')
		return (0);
	return (1);
}

int	ft_format(t_print *tab, char format)
{
	int	cont;

	cont = 0;
	if (format == 'c')
		cont += ft_printchar_format(va_arg(tab->args, int), tab);
	else if (format == 'i' || format == 'd')
		cont += ft_putnbr(va_arg(tab->args, int), tab);
	else if (format == 'p')
		cont += ft_print_ptr(va_arg(tab->args, unsigned long long), tab);
	else if (format == 's')
		cont += ft_printstr_format(va_arg(tab->args, char *), tab);
	else if (format == 'x' || format == 'X')
		cont += ft_print_hex(va_arg(tab->args, unsigned int), format, tab);
	else if (format == 'u')
		cont += ft_print_unsigned(va_arg(tab->args, unsigned int), tab);
	else if (format == '%')
		cont += ft_percent();
	return (cont);
}
