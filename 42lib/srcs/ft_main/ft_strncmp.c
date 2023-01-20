/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:39:26 by agonelle          #+#    #+#             */
/*   Updated: 2022/10/12 09:44:43 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*cp1;
	unsigned char	*cp2;

	i = 0;
	cp1 = (unsigned char *) s1;
	cp2 = (unsigned char *) s2;
	while (cp1[i] && cp2[i] && cp1[i] == cp2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	else
		return (cp1[i] - cp2[i]);
}
