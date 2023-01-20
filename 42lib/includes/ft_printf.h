/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:06:36 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/23 15:36:00 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int		ft_printf(const char *format, ...);
size_t	add_2_res(const char *str, int start, va_list ap);
size_t	ft_putchar_1(char str);
size_t	ft_add_char(va_list ap);
size_t	ft_add_str(va_list ap);
size_t	ft_add_num(va_list ap);
size_t	ft_add_unum(va_list ap);
size_t	ft_add_pont(va_list ap);
size_t	ft_add_hex(va_list ap, char c);
size_t	ft_nbr_len_base(size_t nbr, char *base);
void	ft_put_base(size_t nbr, char *base);
size_t	ft_print_hex(size_t nbr, char *base);

#endif
