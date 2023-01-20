/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_occ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:25:43 by agonelle          #+#    #+#             */
/*   Updated: 2022/10/10 14:26:25 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_count_occ(char const *s1, char const *set)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (s1[index])
	{
		if (ft_strchr(set, s1[index]) && index >= 0)
			count++;
		index++;
	}
	return (count);
}
