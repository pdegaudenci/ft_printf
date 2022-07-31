/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdegaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:33:15 by pdegaude          #+#    #+#             */
/*   Updated: 2022/07/31 16:00:43 by pdegaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_evaluate_flagsbonus(t_print *tab, const char *str, int *pos)
{
	while (str[*pos] == '+' || str[*pos] == '#' || str[*pos] == ' ')
	{
		if (str[*pos] == '+')
		{
			tab->sign = 1;
			*pos = *pos + 1;
		}
		if (str[*pos] == ' ')
		{
			tab->space = 1;
			*pos = *pos + 1;
		}
		if (str[*pos] == '#')
		{
			tab->sharp = 1;
			*pos = *pos + 1;
		}
	}
}

int	ft_applysharp(char format)
{
	int	cont;

	cont = 0;
	if (format == 'x')
		cont += write(1, "0x", 2);
	else
		cont += write(1, "0X", 2);
	return (cont);
}

char	*ft_apply_bonus(char *str, char format, t_print *tab)
{
	char	*temp;

	if (tab->space == 1 && (format == 'd' || format == 'i') && tab->sign == 0)
	{
		temp = ft_strjoin(" ", str);
		free(str);
		return (temp);
	}
	if (tab->sign == 1)
	{
		temp = ft_strjoin("+", str);
		free(str);
		return (temp);
	}
	return (str);
}
