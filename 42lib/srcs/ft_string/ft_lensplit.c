/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:22:19 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/30 12:37:01 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../libft.h"

size_t	ft_lensplit(char **tab)
{
	size_t	len;
	size_t	i;

	len = 1;
	i = 0;
	while (tab[i])
	{
		len++;
		i++;
	}
	return (len);
}
