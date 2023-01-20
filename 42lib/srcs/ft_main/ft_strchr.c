/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:55:05 by agonelle          #+#    #+#             */
/*   Updated: 2022/07/18 11:56:04 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*cp;
	char	cc;

	cp = (char *)s;
	cc = (char)c;
	while (*cp != 0 && *cp != cc)
		cp++;
	if (*cp == cc)
		return (cp);
	else
		return (NULL);
}
