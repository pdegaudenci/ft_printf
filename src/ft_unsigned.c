#include "../include/ft_printf.h"

int	ft_num_len(unsigned	int num)
{
	int	len;

	len = 0;
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
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_print_unsigned(unsigned int n, t_print *tab)
{

	int		cont;
	char	*num;
	char 	*num_w;

	cont = 0;
	num_w = NULL;
	if (n == 0 && tab->wdt == 0)
		 cont+=write(1,"0",1);
 	if (n >= 0 || (tab->wdt > 0))
	{
		num = ft_uitoa(n);
		if( tab->wdt > (int)ft_strlen(num))
		{
			num_w = ft_apply_width(num, tab);
			cont = ft_printstr(num_w);
			free(num_w);
		}
		else 
		{
			cont += ft_printstr(num);
			free(num);
		}			
	}
	return (cont);
}

