/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:33:38 by agonelle          #+#    #+#             */
/*   Updated: 2022/10/10 13:42:49 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*cp1;
	unsigned char	*cp2;

	cp1 = (unsigned char *)s1;
	cp2 = (unsigned char *)s2;
	i = 0;
	while (i < n && (cp1[i] == cp2[i]))
		i++;
	if (i == n)
		return (0);
	else
		return (cp1[i] - cp2[i]);
}
