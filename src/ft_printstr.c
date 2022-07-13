#include "../include/ft_printf.h"

int ft_print_char(int c)
{
    write(1,&c,1);
    return (1);
}

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

int	ft_printstr(char *str)
{
	int	i;

	i = -1;

	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[++i])
		write(1, &str[i], 1);
	return (i);
}

int	ft_percent(void)
{
	write(1, "%", 1);
	return (1);
}