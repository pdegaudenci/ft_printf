/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdegaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:39:18 by pdegaude          #+#    #+#             */
/*   Updated: 2022/08/14 18:50:48 by pdegaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

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

static char	*ft_strrev(char *str, char format)
{
	int		i;
	int		len;
	char	tmp;

	i = 0;
	len = ft_strlen(str) - 1;
	while (len > i)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
		i++;
		len--;
	}
	len = 0;
	while (str[len])
	{
		if (format == 'X')
			str[len] = (char)ft_toupper(str[len]);
		len++;
	}
	return (str);
}

static char	*ft_num_tostring(char *src, long num, int len, char format)
{
	long	aux;
	int		cont;
	long	resto;
	char	*ptr;

	aux = num;
	resto = num;
	cont = 0;
	ptr = (char *)ft_calloc(sizeof(char), (size_t)len + 1);
	while (aux > 0 && cont < len)
	{
		resto = aux % 16;
		ptr[cont++] = (char)src[resto];
		aux /= 16;
	}
	return (ft_strrev(ptr, format));
}

static char	*ft_putbase16(void)
{
	char	*base;
	int		cont;
	int		cont2;

	base = (char *)ft_calloc(16, sizeof(char));
	if (base == NULL)
		return (0);
	cont = 0;
	cont2 = 0;
	while (cont < 10)
	{
		base[cont] = '0' + cont;
		cont++;
	}
	while (cont < 16)
	{
		base[cont] = 'a' + cont2;
		cont++;
		cont2++;
	}
	return (base);
}

char	*ft_itoa_hex(unsigned int n, char format, t_print *tab)
{
	int		len;
	char	*str;
	long	num;
	char	*digitos;

	digitos = ft_putbase16();
	str = NULL;
	num = n;
	len = num_length(num);
	str = ft_num_tostring(digitos, num, len, format);
	if (!str)
		return (0);
	free(digitos);
	if (tab->sharp == 1 & n != 0 && tab->wdt > (int)ft_strlen(str)
		&& tab->zero == 0 && tab->prc < (int)ft_strlen(str))
	{
		digitos = ft_strjoin("0x", str);
		free(str);
		return (digitos);
	}
	return (str);
}
