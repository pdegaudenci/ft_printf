#include "../include/ft_printf.h"

int	ft_print_unsigned(unsigned int n, t_print *tab)
{
	int		cont;
	char	*num;
	char 	*num_w;

	cont = 0;
	if (n == 0 && (tab->wdt == 0 || tab->wdt == 1))
	{
		cont+=write(1,"0",1);
		return (cont);
	} 
 	if (n >= 0 || (tab->wdt > 0) )
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

