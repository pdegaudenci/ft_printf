/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdegaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:40:57 by pdegaude          #+#    #+#             */
/*   Updated: 2022/06/21 14:51:51 by pdegaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_atoi(const char *str)
{
	int				sign;
	unsigned long	num;
	char			*s1;

	s1 = (char *)str;
	num = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			sign *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		num = (*str - 48) + (num * 10);
		str++;
	}
	if (num > 9223372036854775807 && sign == 1)
		return (-1);
	else if (num > 9223372036854775807 && sign == -1)
		return (0);
	return (num * sign);
}
