/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:28:12 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/22 15:05:45 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h" 

int	close_win(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
	}
	exit (0);
	return (0);
}

int	print_key(int keycode, t_vars *vars)
{
	(void) vars;
	if (keycode == 53)
		close_win(keycode, vars);
	return (0);
}
