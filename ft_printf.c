/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdegaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 09:40:43 by pdegaude          #+#    #+#             */
/*   Updated: 2022/07/07 09:41:26 by pdegaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"


t_print *ft_init_tab(t_print *tab)                       
{                       
      tab->wdt = 0;          
      tab->prc = 0;                        
      tab->zero = 0;                        
      tab->pnt = 0;                        
      tab->sign = 0;                        
      tab->tl = 0;                        
      tab->is_zero = 0;                        
      tab->dash = 0;                        
      tab->perc = 0;                        
      tab->space = 0;                        
      return (tab);                       
}


int ft_printf(char const *str, ...)
{
 
    int     cont;
    int lenght_print;
    t_print *tab;
                       
   tab = (t_print *)malloc(sizeof(t_print));                        
   if (!tab)                         
       return (-1);
   tab = ft_init_tab(tab);
    cont = 0;
    lenght_print = 0;
    va_start(tab->args, str);

    while (str[cont])
    {
        if (str[cont] == '%')
        {
            cont++;
            lenght_print += ft_evaluate_flags(tab,str,&cont); 
            
        }
        else
            lenght_print += ft_print_char(str[cont]);
        cont++;
    }
    va_end(tab->args);
    free(tab);
    return (lenght_print);

}

int main(void)
{
  //ft_printf("%i\n%i\n%i\n%i\n%i\n%i\n%i\n", 10, 23, -2, 37, 200, -9999, 977779);  
  //ft_printf("%   d\n",-1);
   //printf("%   d\n",-1);
   //ft_printf("%12d\n",5678);
   //printf("%12d\n",5678);
   //void *ptr = NULL;
   printf("%5c",'c');
   // printf("%05d\n",12);
  //system("leaks a.out");
}