/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:02:44 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/23 15:24:47 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_l)
{	
	t_list	*last;

	if (!*lst)
		*lst = new_l;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new_l;
	}
}	
