/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 10:30:25 by agonelle          #+#    #+#             */
/*   Updated: 2023/01/21 11:27:31 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	syscall_error_return(char *msg, int value_2_return)
{
	perror(msg);
	return (value_2_return);
}

void	syscall_error_exit(char *msg, int value_2_exit)
{
	perror(msg);
	exit(value_2_exit);
}

int	set_errno_and_return(int error, int value_2_return)
{
	errno = error;
	return (value_2_return);
}

void	set_errno_and_exit(int error, char *msg, int value_2_return)
{
	errno = error;
	perror(msg);
	exit(value_2_return);
}
