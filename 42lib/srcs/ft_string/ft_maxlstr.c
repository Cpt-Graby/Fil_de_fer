/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maxlstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:18:18 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/26 12:21:18 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t	ft_maxlstr(char *str1, char *str2)
{
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	if (len1 < len2)
		return (len2);
	else
		return (len1);
}
