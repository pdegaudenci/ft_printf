/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdegaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 09:40:43 by pdegaude          #+#    #+#             */
/*   Updated: 2022/08/11 13:47:31 by pdegaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"

t_print	*ft_init_tab(t_print *tab)
{
	tab->wdt = 0;
	tab->prc = 0;
	tab->pnt = 0;
	tab->sign = 0;
	tab->zero = 0;
	tab->minus = 0;
	tab->space = 0;
	tab->sharp = 0;
	tab->limit = 0;
	return (tab);
}

void	ft_destroy(t_print *tab)
{
	va_end(tab->args);
	free(tab);
}

int	ft_printf(char const *str, ...)
{	
	int		cont;
	int		lenght_print;
	t_print	*tab;

	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	tab = ft_init_tab(tab);
	cont = 0;
	lenght_print = 0;
	va_start(tab->args, str);
	while (str[cont])
	{	
		if (str[cont] == '%')
		{
			cont++;
			lenght_print += ft_evaluate_flags(tab, str, &cont);
			ft_init_tab(tab);
		}
		else
			lenght_print += ft_print_char(str[cont]);
		cont++;
	}
	ft_destroy(tab);
	return (lenght_print);
}
/*
int main(void)
{
	printf("%14.2d\n",-4200);
	ft_printf("%14.2d",-4200);
}*/
