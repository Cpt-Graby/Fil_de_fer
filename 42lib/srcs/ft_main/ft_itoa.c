/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:19:50 by agonelle          #+#    #+#             */
/*   Updated: 2022/10/13 09:54:18 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_itoa(int n)
{
	int		count;
	int		sign;
	char	*dest;

	count = ft_nbrlen(n);
	if (n < 0)
		sign = -1;
	else
		sign = 1;
	dest = ft_calloc(sizeof(*dest), (count + 1));
	if (dest == NULL)
		return (NULL);
	dest[count] = '\0';
	while (count)
	{
		dest[--count] = (n % 10) * sign + '0';
		n /= 10;
	}
	if (sign == -1)
		dest[count] = '-';
	return (dest);
}
