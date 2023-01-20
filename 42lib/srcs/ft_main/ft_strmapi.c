/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:48:03 by agonelle          #+#    #+#             */
/*   Updated: 2022/10/13 10:54:29 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*n_str;

	i = 0;
	n_str = ft_calloc(sizeof(*n_str), ft_strlen(s) + 1);
	if (!n_str)
		return (NULL);
	while (s[i])
	{
		n_str[i] = f(i, s[i]);
		i++;
	}
	n_str[i] = '\0';
	return (n_str);
}
