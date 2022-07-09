/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdegaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:30:34 by pdegaude          #+#    #+#             */
/*   Updated: 2022/07/04 11:13:51 by pdegaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	cont;

	cont = 0;
	if (s == NULL || f == NULL)
		return ;
	while (s[cont])
	{
		(*f)(cont, &s[cont]);
		cont++;
	}			
}
/*
static void ft_upper(unsigned int a, char *s1)
{
	if (*s1 >= 97 && *s1 <= 122)
		*s1 -= 32;
}

int main()
{
	char cadena[]= "hola como estas";
	void(* fptr) (unsigned int, char* );             
  	fptr = ft_upper;  
	ft_striteri(cadena,fptr);
	system("leaks a.out");
	printf("%s",cadena);
}*/
