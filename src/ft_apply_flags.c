#include "../include/ft_printf.h"


static void ft_fill(t_print *tab, char *fill, int cont)
{
    while ( cont >= 0)
    {
        if (tab->zero)
        {
            fill[cont] = '0';
            cont--;
        }  
        else
        {
            fill[cont] = ' ';
            cont--;
        }
    }
}

char	*ft_apply_width(char *str, t_print *tab)
{
    int cont;
    char *str_w;
    char *fill;

    cont = (int)ft_strlen(str);
    cont = tab->wdt - cont;
    fill = (char *)malloc (sizeof(char)*(cont + 1));
    fill[cont--] = '\0';
    ft_fill(tab, fill, cont);
    str_w = ft_strjoin((const char *)fill,(const char *)str);
    free (fill);
    free(str);
    return(str_w);
}