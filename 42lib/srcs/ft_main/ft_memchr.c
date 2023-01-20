/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:26:28 by agonelle          #+#    #+#             */
/*   Updated: 2022/10/10 13:46:14 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cp;

	i = 0;
	cp = (unsigned char *)s;
	while (i < n)
	{
		if (cp[i] == (unsigned char)c)
			return (&cp[i]);
		i++;
	}
	return (NULL);
}
