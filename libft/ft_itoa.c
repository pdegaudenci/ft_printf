/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdegaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:23:27 by pdegaude          #+#    #+#             */
/*   Updated: 2022/06/22 18:06:02 by pdegaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	num_length(long n)
{
	size_t	length_num;

	length_num = 0;
	if (n < 0)
	{
		length_num++;
		n *= -1;
	}
	while (n >= 1)
	{
		length_num++;
		n /= 10;
	}
	return (length_num);
}

static char	*ft_num_tostring(char *ptr, long num, int len, int sign)
{
	if (num != 0)
		ptr = malloc(sizeof(char) * (len + 1));
	else
		return (ptr = ft_strdup("0"));
	if (!ptr)
		return (0);
	if (num < 0)
	{
		sign *= -1;
		num = -num;
	}
	ptr[len] = '\0';
	while (--len)
	{
		ptr[len] = (num % 10) + '0';
		num /= 10;
	}
	if (sign < 0)
		ptr[0] = '-';
	else
		ptr[0] = (num % 10) + '0';
	return (ptr);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	num;
	int		sign;

	num = n;
	len = num_length(num);
	str = 0;
	sign = 1;
	str = ft_num_tostring(str, num, len, sign);
	if (!str)
		return (0);
	return (str);
}
