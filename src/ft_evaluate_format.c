#include "../include/ft_printf.h"

int ft_evaluate_flags(t_print *tab, const char *str, int *pos)
{
    while (ft_isformat(str[*pos]))
    {
        if (str[*pos] == '.')
        {
            tab->pnt = 1; 
            *pos = *pos + 1;
        }
        if (str[*pos] == '-')
        {
            tab->dash = 1; 
            *pos = *pos + 1;
        }
        if( str[*pos] == '+')
        {
            tab->sign = 1;
           *pos = *pos + 1;
        }
          if (str[*pos] == ' ')
        {
            tab->space = 1; 
           *pos = *pos + 1;
        }
        if (str[*pos]== '0' || (str[*pos] >= '0' && str[*pos] <= '9'))
            ft_evaluate_width(tab,str, pos);
    }
    return (ft_format(tab,str[*pos]));
}

void    ft_evaluate_width(t_print *tab,const char *c, int *pos)
{
    if (c[*pos] == '0')
    {
        tab->zero = 1;
        *pos = *pos + 1;
    }
    while (c[*pos] >= '0' && c[*pos] <='9')
    {
        tab->wdt = c[*pos] - '0' + (tab->wdt * 10);
        *pos = *pos + 1;
    }
}

int ft_format(t_print *tab,char c)
{
    int cont;

    cont = 0;
    if (c == 'c')
        cont += ft_print_char(va_arg(tab->args, int));
    else if(c == 'i' || c == 'd')
        cont += ft_putnbr(va_arg(tab->args, int), tab);
    else if (c == 'p')
        cont  += ft_print_ptr(va_arg(tab->args, unsigned long long));
    else if (c == 's')
		cont += ft_printstr(va_arg(tab->args, char *));
    else if (c == 'x' || c == 'X')
		cont += ft_print_hex(va_arg(tab->args, unsigned int), c);
        	else if (c == 'u')
		cont += ft_print_unsigned(va_arg(tab->args, unsigned int));
    else if (c == '%')
		cont += ft_percent();
    return (cont);
}