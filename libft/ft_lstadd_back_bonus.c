/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdegaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:45:51 by pdegaude          #+#    #+#             */
/*   Updated: 2022/06/29 18:58:13 by pdegaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;

	if (*lst == NULL)
	{
		*lst = new;
	
	}
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}

	
}
