/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kino </var/spool/mail/kino>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:18:35 by kino              #+#    #+#             */
/*   Updated: 2023/02/25 22:27:31 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_window_size(t_map *map)
{
	if (map->column >= 0 && map->column < 99)
		map->win_w = 400;
	else if (map->column >= 100 && map->column < 500)
		map->win_w = 800;
	else
		map->win_w = 1200;
	if (map->line >= 0 && map->line < 99)
		map->win_h = 400;
	else if (map->line >= 100 && map->line < 500)
		map->win_h = 800;
	else
		map->win_h = 1200;
}


void	get_barycenter(t_map *map)
{
	int	x;
	int	y;
	int	sum;

	sum = 0;
	x = 0;
	while (x < map->line)
	{
		y = 0;
		while (y < map->column)
		{
			sum += map->coordinate[x][y];
			y++;
		}
		x++;
	}
	map->barycenter.z = (float) sum / (map->column * map->line);
	map->barycenter.x = (float) map->line / 2;
	map->barycenter.y = (float) map->column / 2;
}

float	set_zoom(t_map *map)
{
	float	zoom1;
	float	zoom2;

	if (map->column >= 0 && map->column < 99)
		zoom1 = 10.0;
	else if (map->column >= 100 && map->column < 500)
		zoom1 = 5.0;
	else
		zoom1 = 1.0;
	if (map->line >= 0 && map->line < 99)
		zoom2 = 10.0;
	else if (map->line >= 100 && map->line < 500)
		zoom2 = 5.0;
	else
		zoom2 = 1.0;
	if (zoom1 > zoom2)
		return (zoom2);
	else
		return (zoom1);
}

