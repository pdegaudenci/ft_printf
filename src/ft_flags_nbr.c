
#include "../include/ft_printf.h"

void ft_fill(t_print *tab, char *fill, int cont)
{
    if (tab->sign)
        cont++;
    fill[cont--] = '\0';
    while ( cont >= 0)
    {
        if ( cont == 0 && tab->sign < 0)
        {
            fill[cont] = '-';
           
             break;
        }
        else if (tab->zero == 1)
        {   
            fill[cont] = '0';
           
        }  
        else
        {
            fill[cont] = ' ';
         
        }
        cont--;
    } 
}

char	*ft_apply_width(char *str, t_print *tab)
{
    int cont;
    char *str_w;
    char *fill;
    char *temp;
    
    cont = (int)ft_strlen(str);
    str_w = NULL;
    cont = tab->wdt - cont;
    fill = (char *)malloc (sizeof(char)*(cont + 1));
    ft_fill(tab, fill, cont);
    if (tab->sign < 0)
        str_w = ft_substr((char const*)str,1,ft_strlen(str));
    else
        str_w = ft_substr((char const*)str,0,ft_strlen(str));
    temp= ft_strjoin((const char *)fill,(const char *)str_w);
    free (fill);
    free(str);
    free(str_w);
    return(temp);
}


