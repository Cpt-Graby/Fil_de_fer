/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:05:00 by agonelle          #+#    #+#             */
/*   Updated: 2022/10/13 16:07:59 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nw;

	nw = ft_calloc(sizeof(*nw), 1);
	if (!nw)
		return (NULL);
	nw->content = content;
	nw->next = NULL;
	return (nw);
}
