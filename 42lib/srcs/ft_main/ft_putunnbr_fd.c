/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunnbr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:12:27 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/08 15:22:59 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_putunnbr_fd(unsigned int n, int fd)
{
	if (n > 9)
	{
		ft_putnbr_fd((n) / 10, fd);
		ft_putnbr_fd((n) % 10, fd);
	}
	else
		ft_putchar_fd((n + '0'), fd);
}	
