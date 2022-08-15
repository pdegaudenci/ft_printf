/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdegaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 09:38:20 by pdegaude          #+#    #+#             */
/*   Updated: 2022/08/11 19:48:50 by pdegaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include <stddef.h>

typedef struct s_print
{
	va_list	args;
	int		wdt;
	int		prc;
	int		pnt;
	int		minus;
	int		zero;
	int		sign;
	int		space;
	int		sharp;
	char	format;
	int		limit;
}	t_print;

t_print	*ft_init_tab(t_print *tab);
void	ft_destroy(t_print *tab);
int		ft_format(t_print *tab, char c);
int		ft_printf(char const *str, ...);
int		ft_isformat(char c);
int		ft_evaluate_flags(t_print *tab, const char *str, int *pos);
void	ft_evaluate_width(t_print *tab, const char *c, int *pos);
void	ft_fill(t_print *tab, char *fill, int cont);
char	*ft_apply_width(char *num, t_print *tab);
int		ft_putnbr(int n, t_print *tab);
int		ft_print_char(int c);
int		ft_printchar_format(int c, t_print *tab);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *s);
int		ft_printstr(char *str);
int		ft_printstr_flags(char *str, t_print *tab);
int		ft_printstr_format(char *str, t_print *tab);
void	ft_putstr(char *str);
int		ft_hex_len(unsigned	int num);
void	ft_put_hex(unsigned int num, const char format, t_print *tab);
int		ft_print_hex(unsigned int num, const char format, t_print *tab);
int		ft_put_wdt(t_print *tab, int num);
int		ft_print_ptr(unsigned long long ptr, t_print *tab);
int		ft_ptr_len(unsigned long num);
char	*ft_uitoa(unsigned int n);
int		ft_print_unsigned(unsigned int n, t_print *tab);
int		ft_num_len(unsigned int num);
int		ft_percent(void);
void	ft_evaluate_prec(t_print *tab, const char *c, int *pos);
char	*ft_apply_width_str(char *str, t_print *tab);
int		ft_apply_wdtptr(int size);
int		put_wdt(t_print *tab);
void	ft_apply_prec(t_print *tab, char *str);
char	*ft_itoa_hex(unsigned int n, char format, t_print *tab);
char	*ft_applyflags_nbr(char *str_w, char *fill, t_print *tab, char *str);
int		ft_evallwdtprc_nbr(char *num, char *num_w, t_print *tab, int len);
void	ft_evaluate_flagsbonus(t_print *tab, const char *str, int *pos);
char	*ft_apply_bonus(char *str, char format, t_print *tab);
int		ft_applysharp(char format);
int		ft_null(char *str, t_print *tab, int size);
char	*ft_applyalign_str(char *str, char *fill, t_print *tab);
void	ft_fill_str(char *fill, int size);
int		ft_eval_wdt(t_print *tab, unsigned int num, char format);
int		ft_prec_hex(unsigned int num, char format, t_print *tab, int cont);
void	ft_fill_str_nbr(char *fill, int size, t_print *tab);
char	*ft_wdtprc_pnt(t_print *tab, char *fill, int wdt, char *str_w);
char	*ft_apply_align(char *fill, char *str, t_print *tab);
char	*ft_flags_bonus(char *str, t_print *tab, int minu, int wdt);
int		ft_eval_zero(int n, t_print *tab);
char	*ft_strnbr(t_print *tab, char *str);
int		ft_printstr_flagsnull(char *str, t_print *tab, int wdt);
#endif