/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdegaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:37:39 by pdegaude          #+#    #+#             */
/*   Updated: 2022/08/04 16:44:40 by pdegaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_evalwdtprc(char *num, t_print *tab, unsigned int n, char *num_w)
{
	int	cont;

	cont = 0;
	num = ft_uitoa(n);
	if (tab->wdt > (int)ft_strlen(num) || (tab->pnt == 1
			&& tab->prc > (int)ft_strlen(num)))
	{
		num_w = ft_apply_width(num, tab);
		cont = ft_printstr(num_w);
		free(num_w);
	}
	else
	{
		cont += ft_printstr(num);
		free(num);
	}
	return (cont);
}

int	ft_print_unsigned(unsigned int n, t_print *tab)
{
	int		cont;
	char	*num;
	char	*num_w;

	cont = 0;
	num = NULL;
	num_w = NULL;
	if (n == 0 && tab->pnt == 1 && tab->prc == 0)
		return (0);
	if (n == 0 && (tab->wdt == 0 || tab->wdt == 1) && tab->pnt == 0)
	{
		cont += write(1, "0", 1);
		return (cont);
	}
	if (n >= 0 || (tab->wdt > 0) || (tab->pnt == 1
			&& tab->prc > (int)ft_strlen(num)))
		return (cont + ft_evalwdtprc(num, tab, n, num_w));
	return (cont);
}
