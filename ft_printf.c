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
#define ULONG_MAX (__LONG_MAX__ *2UL+1UL)

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
            ft_init_tab(tab);     
        }
        else
            lenght_print += ft_print_char(str[cont]);
        cont++;
    }
    va_end(tab->args);
    free(tab);
    return (lenght_print);

}
/*
int main(void)
{
  //ft_printf("%i\n%i\n%i\n%i\n%i\n%i\n%i\n", 10, 23, -2, 37, 200, -9999, 977779);  
  //ft_printf("%   d\n",-1);
   //printf("%   d\n",-1);
   //ft_printf("%12d\n",5678);
   //printf("%12d\n",5678);
   //void *ptr = NULL;
   //printf("%5c",'c');
 
  
   printf("Salidas PRINTF \n");

printf(" %05d ", -15);
printf(" %06d ", -16);


printf(" %015d ", 9223372036854775807LL);
ft_printf(" %09d %010d %011d %012d %013d %014d %015d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
//printf(" %013d", INT_MAX);
//printf(" %014d ", LONG_MAX);


//printf(" %04d \n", -14);
//ft_printf(" %04d ", -14);
 ft_printf("%04d\n",12);
 ft_printf("%04d\n",-12);
system("leaks a.out") ;
// system("leaks a.out");

ft_printf(" %05d ", -15);
ft_printf(" %06d ", -16);

ft_printf(" %09d %010d %011d %012d %013d %014d %015d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
ft_printf("Numero int min : %010d \n",INT_MAX);
printf("Numro int min     : %010d \n",INT_MIN);
//ft_printf("    %014d %015d\n", , , , 0, -42);
//printf(" %013d \n", ULONG_MAX);
//ft_printf("%015d \n", -42);
 
 printf(" %04u \n", 9);
printf(" %01u\n ", 10);
ft_printf(" %04u \n", 9);
ft_printf(" %01u\n ", 10);



ft_printf("  %020u  \n", -10);
printf("%020u  \n", -10);
//printf(" %013u   ", UINT_MAX);
//printf(" %014u ", ULONG_MAX);
//printf("\n");
//ft_printf(" %013u   ", UINT_MAX);
//ft_printf(" %014u ", ULONG_MAX);
//printf("%014u %015u\n",  0, -42);
//ft_printf("%014u %015u\n",  0, -42);
//printf("%u\n",  0);
//ft_printf("%u\n",  0);
////printf("%12u\n",  0);
ft_printf("%010u\n",  0);
//system("leaks a.out");
}*/