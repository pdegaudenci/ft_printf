/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdegaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:18:23 by pdegaude          #+#    #+#             */
/*   Updated: 2022/07/26 16:29:49 by pdegaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_evallwdtprc_nbr(char *num, char *num_w, t_print *tab, int len)
{
	if ((tab->wdt > 0 && tab->wdt > (int)ft_strlen(num)) || tab->pnt == 1)
	{
		num_w = ft_apply_width(num, tab);
		len = ft_printstr(num_w);
		free(num_w);
	}
	else
	{
		len = ft_printstr(num);
		free(num);
	}	
	return (len);
}

int	ft_putnbr(int n, t_print *tab)
{
	int		len;
	char	*num;
	char	*num_w;

	if (n < 0)
		tab->sign = -1;
	len = 0;
	num_w = NULL;
	if (n == 2147483647)
		return (write(1, "2147483647", 10));
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	num = ft_itoa(n);
	if (num != NULL)
	{
		len += ft_evallwdtprc_nbr(num, num_w, tab, len);
	}
	return (len);
}
