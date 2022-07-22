#include "../include/ft_printf.h"

int	ft_hex_len(unsigned	int num)
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

void	ft_put_hex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, format);
		ft_put_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_print_char((num + '0'));
		else
		{
			if (format == 'x')
				ft_print_char(num - 10 + 'a');
			if (format == 'X')
				ft_print_char(num - 10 + 'A');
		}
	}
}

int	ft_print_hex(unsigned int num, const char format, t_print *tab)
{
	int cont;
	cont = 0;

	if ((num == 0 && (tab->wdt - 1) <= 0))
		 cont+=write(1,"0",1);
	else
	{
		if (tab->dash == 1)
		{
			tab->zero = 0;
			ft_put_hex(num, format);
			cont += ft_put_wdt(tab,num);
		}
		else
		{
			cont += ft_put_wdt(tab,num);
			ft_put_hex(num, format);
		}
			
	}
	return (cont + ft_hex_len(num));
}

