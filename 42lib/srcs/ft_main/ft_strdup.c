/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:00:04 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/29 10:09:49 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*cp;

	len = ft_strlen(s);
	i = 0;
	cp = ft_calloc(sizeof(*cp), (len + 1));
	if (!cp)
		return (NULL);
	while (*(s + i) != 0)
	{
		*(cp + i) = *(s + i);
		i++;
	}
	return (cp);
}
