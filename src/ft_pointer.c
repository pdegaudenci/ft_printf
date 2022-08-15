/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdegaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:30:57 by pdegaude          #+#    #+#             */
/*   Updated: 2022/08/14 18:47:04 by pdegaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_put_ptr(unsigned long num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_print_char((num + '0'));
		else
			ft_print_char((num - 10 + 'a'));
	}
}

int	ft_apply_wdtptr(int size)
{
	int	cont;

	cont = 0;
	while (size > 0)
	{
		write(1, " ", 1);
		size--;
		cont++;
	}
	return (cont);
}

int	ft_print_ptr(unsigned long long ptr, t_print *tab)
{
	int	print_length;

	print_length = 0;
	if (ptr == 0)
	{
		if (tab->minus == 0 && tab->wdt > ft_ptr_len(ptr) + 2)
			print_length += ft_apply_wdtptr(tab->wdt - 3);
		print_length += write(1, "0x", 2);
		print_length += write(1, "0", 1);
		if (tab->minus == 1 && tab->wdt > ft_ptr_len(ptr) + 2)
			print_length += ft_apply_wdtptr(tab->wdt - 3);
	}		
	else
	{
		if (tab->minus == 0 && tab->wdt > ft_ptr_len(ptr) + 2)
			print_length += ft_apply_wdtptr(tab->wdt - (ft_ptr_len(ptr) + 2));
		print_length += write(1, "0x", 2);
		ft_put_ptr(ptr);
		if (tab->minus == 1 && tab->wdt > ft_ptr_len(ptr) + 2)
			print_length += ft_apply_wdtptr(tab->wdt - (ft_ptr_len(ptr) + 2));
		print_length += ft_ptr_len(ptr);
	}
	if (print_length < tab->wdt && tab->minus == 1)
		print_length += ft_apply_wdtptr(tab->wdt - print_length);
	return (print_length);
}
