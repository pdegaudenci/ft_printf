/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdegaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:01:24 by pdegaude          #+#    #+#             */
/*   Updated: 2022/08/11 13:40:08 by pdegaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_num_len(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_num_len(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	num[len - 1] = n % 10 + 48;
	n = n / 10;
	len--;
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_ptr_len(unsigned long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

int	ft_printstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	return (i);
}

int	ft_eval_zero(int n, t_print *tab)
{
	char	*num_w;
	int		len;

	len = -1;
	num_w = NULL;
	if (n == 0 && tab->pnt == 1
		&& tab->wdt > 0 && tab->prc == 0)
	{
		len = 0;
		num_w = (char *)malloc((size_t)tab->wdt + 1);
		ft_fill_str(num_w, tab->wdt);
		len += ft_printstr(num_w);
		free(num_w);
		return (len);
	}
	if (n == 0 && tab->pnt == 1
		&& tab->prc == 0 && tab->wdt == 0)
		return (0);
	return (len);
}
