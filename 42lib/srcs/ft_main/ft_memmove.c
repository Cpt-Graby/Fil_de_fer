/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:26:00 by agonelle          #+#    #+#             */
/*   Updated: 2022/10/12 16:07:27 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*cp_s;
	unsigned char	*cp_d;
	size_t			i;

	i = 0;
	if (n == 0)
		return (dest);
	if (!dest && !src)
		return (NULL);
	cp_s = (unsigned char *) src;
	cp_d = (unsigned char *) dest;
	if (cp_s < cp_d)
	{
		while (n--)
			cp_d[n] = cp_s[n];
	}
	else
	{
		while (i < n)
		{
			cp_d[i] = cp_s[i];
			i++;
		}
	}
	return (dest);
}
