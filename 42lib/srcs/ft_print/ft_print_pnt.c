/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pnt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 07:50:10 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/08 12:53:16 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t	ft_add_pont(va_list ap)
{
	size_t	count;
	size_t	p;
	char	*base;

	count = 2;
	base = "0123456789abcdef";
	p = va_arg(ap, size_t);
	ft_putstr_fd("0x", 1);
	if (p == 0)
	{
		count += 1;
		ft_putstr_fd("0", 1);
		return (count);
	}
	ft_put_base(p, base);
	count += ft_nbr_len_base(p, base);
	return (count);
}
