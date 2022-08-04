/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdegaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 09:40:43 by pdegaude          #+#    #+#             */
/*   Updated: 2022/07/26 18:19:04 by pdegaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"

t_print	*ft_init_tab(t_print *tab)
{
	tab->wdt = 0;
	tab->prc = 0;
	tab->zero = 0;
	tab->pnt = 0;
	tab->sign = 0;
	tab->is_zero = 0;
	tab->dash = 0;
	tab->space = 0;
	tab->sharp = 0;
	tab->max = 0;
	tab->limit = 1;
	return (tab);
}

void	ft_destroy(t_print *tab)
{
	va_end(tab->args);
	free(tab);
}

int	ft_printf(char const *str, ...)
{	
	int		cont;
	int		lenght_print;
	t_print	*tab;

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
			lenght_print += ft_evaluate_flags(tab, str, &cont);
			ft_init_tab(tab);
		}
		else
			lenght_print += ft_print_char(str[cont]);
		cont++;
	}
	ft_destroy(tab);
	return (lenght_print);
}
/*
int main(void)
{
        ---- BASICOS ---
  //ft_printf("%i\n%i\n%i\n%i\n%i\n%i\n%i\n", 10, 23, -2, 37, 200, -9999, 977779);  
  //ft_printf("%   d\n",-1);
   //printf("%   d\n",-1);
   //ft_printf("%12d\n",5678);
   //printf("%12d\n",5678);
   //void *ptr = NULL;
 
   //printf("%5c",'c');
 
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
ft_printf("    %014d %015d\n", , , , 0, -42);
printf(" %013d \n", ULONG_MAX);
ft_printf("%015d \n", -42);
 
 // UNSIGNED
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
////printf("%12u\n",  0);
ft_printf("%010u\n",  0);test

ft_printf("%04u\n ", 9);
ft_printf("%01u \n", 10);
printf(" %012u h\n", LONG_MIN);
ft_printf(" %012u ", LONG_MIN);
//printf("%u\n",  0);
//ft_printf("%u\n",  0);
//printf("%u\n", LONG_MIN);
//ft_printf("%u\n ", LONG_MIN);
//printf("%u\n", LONG_MAX);
//ft_printf("%u\n", LONG_MAX);
printf(" %u %u %u %u %u %u %u\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
ft_printf(" %u %u %u %u %u %u %u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

// HEXADECIMAL:
int size;
size=printf(" %x ", -145);
printf(" Tamaño:%i\n ", size);
size=ft_printf(" %x ", -145);
printf(" Tamaño:%i\n ", size);
printf(" %03x\n ", 1);
ft_printf(" %03x ", 1);

//printf("%012x\n ", 0);
//ft_printf("%012x ", 0);
printf("%01x\n ", 0);
ft_printf("%01x ", 0);
printf("%012x\n", LONG_MIN);
ft_printf("%012x", LONG_MIN);
//void *ptr;
ft_printf("%20s", "Hola");

printf(" NULL %s NULL \n ", NULL);
ft_printf(" NULL %s NULL\n ", NULL);
//printf("%-5d", -11);
//ft_printf("%-5d", -11)

int size= printf(" %-1u", 0);
printf("Size print original:%i\n",size);
// size = ft_printf(" %-1u", 0 );
// printf("Size print:%i",size);
int size = printf("%-14u\n", 0);
//printf("Size print original:%i\n",size);
size = ft_printf("%-14u",  0);

//printf("Size print :%i\n",size);
int size= printf("%-11p%-12p", INT_MIN, INT_MAX);
printf("Size print:%i\n",size);
size = ft_printf("%-11p%-12p", INT_MIN, INT_MAX);
printf("Size print:%i",size);

int size= printf(" %p %p ", 0, 0);
printf("Size print1:%i\n",size);
size = ft_printf(" %p %p ", 0, 0);
printf("Size print2:%i",size);
int size= printf(" %-3x ", 1);
printf("Size print1:%i\n",size);
size = ft_printf(" %-3x ", 1);
printf("Size print2:%i",size);
int size= printf( " %.2d ", -10);

printf("Size print1:%i\n",size);
size = ft_printf(" %.2d ", -10);
printf("Size print2:%i",size);


int size= printf("%#x ", -99);

printf("Size print1:%i\n",size);
size = ft_printf(" %.2x ", -1);
printf("Size print2:%i",size);
//int size= printf(" %-3d ", -101);

printf(" %-9d ", INT_MAX);
int size = ft_printf(" %-9d ", INT_MAX);
printf("Size print2:%i",size);
int size= printf("% d", INT_MAX);

printf("Size print1:%i\n", size);
size = ft_printf("% d", INT_MAX);
printf("Size print2:%i",size);

int size= printf("%+d", INT_MAX);

printf("Size print1:%i\n", size);
size = ft_printf("%+d", INT_MAX);
printf("Size print2:%i",size);

int size;

size =printf("%10.1s", "21-school.ru");
printf("  Size print2:%i\n",size);
size = ft_printf("%10.1s", "21-school.ru");
printf("  Size print2:%i\n",size);

size =printf("%1.s", "21-school.ru");
printf("  Size print2:%i\n",size);
size = ft_printf("%1.s", "21-school.ru");
printf("  Size print2:%i",size);

int size;

size =printf("%.11d", (int)-2147483648);
printf("  Size print2:%i\n",size);
size = ft_printf("%.11d", (int)-2147483648);
printf("  Size print2:%i\n",size);


//system("leaks a.out");
}*/
