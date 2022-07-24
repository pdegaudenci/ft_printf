#include "../include/ft_printf.h"

int ft_putnbr(int n, t_print *tab)
{
	int len;
	char *num;
	char *num_w;
	
	if (n < 0)
		tab->sign = -1;
	len = 0;
	if (n == 2147483647)
		return (write(1,"2147483647",10));
	if (n == -2147483648)
		return (write(1,"-2147483648",11));
	num = ft_itoa(n);
	num_w = NULL;
	if (num != NULL)
	{
		if ((tab->wdt > 0 && tab->wdt > (int)ft_strlen(num)) || tab->pnt == 1)
		{
			num_w = ft_apply_width(num, tab);
			len = ft_printstr(num_w);
			free(num_w);
		}
		else
		{
			len = ft_printstr(num);
			free(num);
		}	
	}
	return (len);
}
