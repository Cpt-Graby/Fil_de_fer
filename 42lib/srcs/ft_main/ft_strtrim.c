/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:42:11 by agonelle          #+#    #+#             */
/*   Updated: 2022/10/13 10:10:39 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	ft_inset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	ind_s;
	size_t	ind_e;
	char	*dest;

	if (!s1)
		return (NULL);
	else if (!set)
		return (ft_strdup(s1));
	if (ft_strncmp(s1, set, ft_strlen(s1)) == 0)
		return (ft_strdup(""));
	i = 0;
	while (ft_inset(s1[i], set) && s1[i])
		i++;
	ind_s = i;
	i = ft_strlen(s1) - 1;
	while (i > ind_s && ft_inset(s1[i], set))
		i--;
	ind_e = i;
	dest = ft_calloc(sizeof(*dest), ((ind_e - ind_s + 1) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	ft_strlcpy(dest, s1 + ind_s, ((ind_e - ind_s + 1) + 1));
	return (dest);
}
