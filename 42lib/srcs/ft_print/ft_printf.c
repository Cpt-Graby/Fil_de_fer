/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:16:45 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/23 15:36:38 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	count;
	va_list	ap;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += add_2_res(format, i, ap);
		}
		else
			count += ft_putchar_1(format[i]);
		i++;
	}
	return (count);
}

size_t	add_2_res(const char *str, int start, va_list ap)
{
	size_t	add_count;

	add_count = 0;
	if (str[start] == '%')
		add_count = ft_putchar_1(str[start]);
	else if (str[start] == 'c')
		add_count = ft_add_char(ap);
	else if (str[start] == 's')
		add_count = ft_add_str(ap);
	else if (str[start] == 'd' || str[start] == 'i')
		add_count = ft_add_num(ap);
	else if (str[start] == 'u')
		add_count = ft_add_unum(ap);
	else if (str[start] == 'x' || str[start] == 'X')
		add_count = ft_add_hex(ap, str[start]);
	else if (str[start] == 'p')
		add_count = ft_add_pont(ap);
	else
		ft_putchar_fd(str[start], 1);
	return (add_count);
}
