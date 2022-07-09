#include "../include/ft_printf.h"

int ft_evaluate_flags(t_print *tab, const char *str, int pos)
{
    while (ft_isformat(str[pos]))
    {
        if (str[pos] == '.')
        {
            tab->pnt = 1; 
            pos++;
        }
        if (str[pos] == '-')
        {
            tab->dash = 1; 
            pos++;
        }
          if (str[pos] == ' ')
        {
            tab->sp = 1; 
            pos++;
        }
    }


    printf("%i\n",pos);
    return (ft_format(tab->args,str[pos]));
}
int ft_format(va_list arg,char c)
{
    int cont;

    cont = 0;
    if (c == 'c')
        cont += ft_print_char(va_arg(arg, int));
    else if(c == 'i' || c == 'd')
        cont += ft_putnbr(va_arg(arg, int));
    else if (c == 'p')
        cont  += ft_print_ptr(va_arg(arg, unsigned long long));
    else if (c == 's')
		cont += ft_printstr(va_arg(arg, char *));
    else if (c == 'x' || c == 'X')
		cont += ft_print_hex(va_arg(arg, unsigned int), c);
        	else if (c == 'u')
		cont += ft_print_unsigned(va_arg(arg, unsigned int));
    else if (c == '%')
		cont += ft_percent();
    return (cont);
}