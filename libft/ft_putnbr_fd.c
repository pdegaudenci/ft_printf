/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdegaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:52:56 by pdegaude          #+#    #+#             */
/*   Updated: 2022/06/22 16:30:06 by pdegaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (fd)
	{
		if (n == -2147483648)
			write(fd, "-2147483648", 11);
		else
		{
			if (n < 0)
			{
				ft_putchar_fd('-', fd);
				n *= -1;
				ft_putnbr_fd(n, fd);
			}
			else if (n < 10)
				ft_putchar_fd((n + '0'), fd);
			else
			{
				ft_putnbr_fd(n / 10, fd);
				ft_putchar_fd(((n % 10) + '0'), fd);
			}
		}
	}
}
