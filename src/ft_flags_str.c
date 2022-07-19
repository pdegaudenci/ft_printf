#include "../include/ft_printf.h"

char	*ft_apply_width_str(char *str, t_print *tab)
{
    int cont;
    char *str_w;
    char *fill;
    char *temp;
    
    cont = (int)ft_strlen(str);
    str_w = NULL;
    cont = tab->wdt - cont;
    fill = (char *)malloc (sizeof(char)*(cont + 1));
    tab->zero = 0;
    ft_fill(tab, fill, cont);
    str_w = ft_substr((char const*)str,0,ft_strlen(str));
    if (tab->dash > 0)  
        temp= ft_strjoin((const char *)str_w,(const char *)fill);
    else 
        temp= ft_strjoin((const char *)fill,(const char *)str_w);
    free (fill);
    free(str_w);
    return(temp);
}