/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:57:53 by agonelle          #+#    #+#             */
/*   Updated: 2022/10/13 09:54:45 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;
	char	*dest;
	size_t	i;

	i = 0;
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	dest = ft_calloc(sizeof(*dest), (l1 + l2 + 1));
	if (!dest)
		return (NULL);
	while (i < l1)
	{
		dest[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < l2)
	{
		dest[l1 + i] = s2[i];
		i++;
	}
	dest[l1 + l2] = '\0';
	return (dest);
}
