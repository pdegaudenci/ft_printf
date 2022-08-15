/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdegaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:34:03 by pdegaude          #+#    #+#             */
/*   Updated: 2022/08/15 03:40:54 by pdegaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_printstr_flags(char *str, t_print *tab)
{
	int	i;
	int	wdt;

	if (tab->wdt > (int)ft_strlen(str))
		return (ft_printstr_flagsnull(str, tab, tab->prc));
	wdt = 0 ;
	if ((tab->pnt == -1 || tab->pnt == 1) && tab->wdt > 0 && tab->minus == 0)
	{
		while (wdt < tab->wdt - tab->prc)
			wdt += write(1, " ", 1);
	}
	i = -1;
	while (str[++i])
	{
		if ((tab->pnt > 0 || tab->pnt == -1) && tab->prc == i)
			break ;
		write(1, &str[i], 1);
	}
	if ((tab->pnt == -1 || tab->pnt == 1) && tab->wdt > 0 && tab->minus == 1)
	{
		while (wdt < tab->wdt - tab->prc)
			wdt += write(1, " ", 1);
	}
	return (i + wdt);
}

int	ft_printstr_flagsnull(char *str, t_print *tab, int wdt)
{
	int	i;

	if ((tab->pnt == -1 || tab->pnt == 1) && tab->wdt > (int)ft_strlen(str)
		&& tab->minus == 0)
	{
		while (wdt < tab->wdt)
			wdt += write(1, " ", 1);
	}
	i = -1 ;
	while (str[++i])
	{
		if (str[i] != ' ' && i < wdt)
			wdt += write(1, &str[i], 1);
		else
			wdt++;
	}
	if ((tab->pnt == -1 || tab->pnt == 1) && tab->wdt > (int)ft_strlen(str)
		&& tab->minus == 1)
	{
		wdt = tab->prc;
		while (wdt < tab->wdt)
			wdt += write(1, " ", 1);
	}
	return (wdt);
}

int	ft_null(char *str, t_print *tab, int size)
{
	int		cont;
	char	*temp;
	char	*str_w;

	cont = 0;
	temp = NULL;
	temp = (char *)malloc(ft_strlen(str) + 1);
	while (cont < size)
	{
		temp[cont] = str[cont];
		cont++;
	}
	temp[cont] = '\0';
	if (tab->wdt > (int)ft_strlen(str) || tab->pnt == -1
		|| (tab->pnt == 1 && tab->prc < (int)ft_strlen(str)))
	{
		str_w = ft_apply_width_str(temp, tab);
		cont = ft_printstr_flags(str_w, tab);
		free(temp);
		free(str_w);
		return (cont);
	}
	cont = write(1, str, 6);
	free(temp);
	return (cont);
}

int	ft_printstr_format(char *str, t_print *tab)
{
	int		cont;
	char	*str_w;

	if (str == NULL)
		return (ft_null("(null)", tab, 6));
	if (tab->wdt > (int)ft_strlen(str))
		str_w = ft_apply_width_str(str, tab);
	else
		return (ft_printstr_flags(str, tab));
	cont = ft_printstr_flags(str_w, tab);
	free(str_w);
	if (tab->prc == 1 && tab->wdt == 1)
		return (1);
	return (cont);
}
