/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:37:53 by agonelle          #+#    #+#             */
/*   Updated: 2022/10/12 17:05:02 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*cpb;
	char	*cpl;

	cpb = (char *)big;
	cpl = (char *)little;
	i = 0;
	if (*cpl == '\0' || cpl == NULL)
		return (cpb);
	while (cpb[i] && i < len)
	{
		j = 0;
		while (cpl[j] == cpb[i + j] && i + j < len && cpl[j] && cpb[i + j])
			j++;
		if (!cpl[j])
			return (cpb + i);
		i++;
	}
	return (NULL);
}
