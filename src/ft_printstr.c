#include "../include/ft_printf.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_printstr_flags(char *str, t_print *tab)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (tab->pnt > 0 && tab->prc == i)
			break;
		write(1, &str[i], 1);
	}
	return (i);
}

int ft_printstr_format(char *str, t_print *tab)
{
    int cont;
    char *str_w;

	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	if (tab->wdt > (int)ft_strlen(str))
		str_w = ft_apply_width_str(str,tab);
	else
		return (ft_printstr_flags(str,tab));
    cont = ft_printstr_flags(str_w,tab);
	free(str_w);
	return (cont);
}

