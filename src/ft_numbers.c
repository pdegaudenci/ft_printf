/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdegaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:18:23 by pdegaude          #+#    #+#             */
/*   Updated: 2022/08/15 05:09:52 by pdegaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/ft_printf.h"

int	ft_evallwdtprc_nbr(char *num, char *num_w, t_print *tab, int len)
{
	if ((tab->wdt > 0 && tab->wdt > (int)ft_strlen(num)) || tab->pnt == 1)
	{
		num_w = ft_apply_width(num, tab);
		num_w = ft_apply_bonus(num_w, 'd', tab);
		len = ft_printstr(num_w);
		free(num_w);
	}
	else
	{	
		num = ft_apply_bonus(num, 'd', tab);
		len = ft_printstr(num);
		free(num);
	}	
	return (len);
}

static int	ft_evallimits(int n, t_print *tab, char *num_w, int len)
{
	tab->limit = 1;
	if (n == 2147483647)
		return (ft_evallwdtprc_nbr((char *)ft_strdup("2147483647"),
				num_w, tab, len));
	tab->sign = 0;
	tab->space = 0;
	return (ft_evallwdtprc_nbr((char *)ft_strdup("-2147483648"),
			num_w, tab, len - 1));
}

char	*ft_wdtprc_pnt(t_print *tab, char *fill, int wdt, char *str_w)
{
	char	*str_ret;
	int		cont;

	cont = wdt - (int)ft_strlen(fill);
	str_w = (char *)malloc((size_t)cont + 1);
	ft_fill_str_nbr(str_w, cont, tab);
	str_ret = ft_apply_align(str_w, fill, tab);
	free(str_w);
	free(fill);
	return (str_ret);
}

char	*ft_flags_bonus(char *str, t_print *tab, int dash, int wdt)
{
	char	*str_w;
	char	*fill;

	fill = NULL;
	str_w = NULL;
	if (wdt < (int) ft_strlen(str) && tab->pnt == 1
		&& tab->prc < (int) ft_strlen(str))
		fill = str;
	else
		fill = ft_applyflags_nbr(str_w, fill, tab, str);
	tab->minus = dash;
	if (tab->sign == 1 && fill[0] != '+')
	{
		fill[0] = '+';
		tab->sign = 0;
	}
	if (tab->pnt == 1 && wdt - (int)ft_strlen(fill) > 0)
		return (ft_wdtprc_pnt(tab, fill, wdt, str_w));
	return (fill);
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
	len = ft_eval_zero(n, tab);
	if (len != -1)
		return (len);
	len = 0;
	if (n == 2147483647 || n == -2147483648)
		return (ft_evallimits(n, tab, num_w, len));
	num = ft_itoa(n);
	if (tab->sign == 1 && tab->zero == 0 && tab->prc <= (int)ft_strlen(num))
	{
		num = ft_apply_bonus(num, 'd', tab);
		tab->sign = 0;
	}	
	if (num != NULL)
		len += ft_evallwdtprc_nbr(num, num_w, tab, len);
	return (len);
}
