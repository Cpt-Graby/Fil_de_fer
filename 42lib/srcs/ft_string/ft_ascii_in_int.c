/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ascii_in_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:07:34 by agonelle          #+#    #+#             */
/*   Updated: 2023/02/07 14:24:57 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_ascii_in_int(char *num_string)
{
	int	len;

	len = ft_strlen(num_string);
	if (len > 11)
		return (0);
	else if (len == 11 && num_string[0] == '-')
	{
		if (ft_strncmp(num_string, "-2147483648", 12) > 0)
			return (0);
		else
			return (1);
	}
	else if (len > 10 && num_string[0] != '-')
		return (0);
	else if (len == 11 && num_string[0] != '-')
	{
		if (ft_strncmp(num_string, "2147483647", 11) > 0)
			return (0);
		else
			return (1);
	}
	else
		return (1);
}
