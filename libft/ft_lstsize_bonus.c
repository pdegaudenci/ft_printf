/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdegaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:42:29 by pdegaude          #+#    #+#             */
/*   Updated: 2022/06/29 16:59:16 by pdegaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*p;
	int		cont;

	if (lst == NULL)
		return (0);
	cont = 0;
	p = lst;
	while (p)
	{
		cont++;
		p = p->next;
	}
	return (cont);
}
