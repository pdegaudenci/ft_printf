/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdegaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 09:38:20 by pdegaude          #+#    #+#             */
/*   Updated: 2022/07/07 09:40:34 by pdegaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

typedef struct s_print                       
{                        
      va_list  args;    // arg to print out                    
      int   wdt;        // width                
      int   prc;        // precision              
      int   zero;       // zero padding               
      int   pnt;        // .     
      int   dash;       // -               
      int   tl;         // total_length (return value)              
      int   sign;       // pos or neg number               
      int   is_zero;    // is number zero                 
      int   perc;       // %               
      int   sp;         // space flag ' '            
}    t_print;

t_print *ft_init_tab(t_print *tab) ;
int ft_format(va_list arg,char c);
int     ft_printf(char const *str, ...);
int	ft_isformat(char c);
int ft_evaluate_flags(t_print *tab, const char *str, int pos);
int	    ft_putnbr(int n);
int ft_print_char(int c);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *s);
int	ft_printstr(char *str);
void	ft_putstr(char *str);
int	ft_hex_len(unsigned	int num);
void	ft_put_hex(unsigned int num, const char format);
int	ft_print_hex(unsigned int num, const char format);
int	ft_print_ptr(unsigned long long ptr);
char	*ft_uitoa(unsigned int n);
int	ft_print_unsigned(unsigned int n);
int	ft_num_len(unsigned	int num);
int	ft_percent(void);
# endif
