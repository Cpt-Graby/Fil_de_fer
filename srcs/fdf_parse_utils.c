/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kino </var/spool/mail/kino>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:18:35 by kino              #+#    #+#             */
/*   Updated: 2023/03/06 15:23:01 by agonelle         ###   ########.fr       */
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

int	check_in_screen(t_vec3 point_to_check, int max_width, int max_height)
{
	if ((int) point_to_check.x < 0 || (int) point_to_check.x > max_width
		|| (int) point_to_check.y < 0 || (int) point_to_check.y > max_height)
		return (0);
	return (1);
}

int	check_4_corner_in_screen(int zoom, t_vec3 point, t_vec3 screen, t_map *map)
{
	point.x = 0;
	point.y = 0;
	point.z = map->coordinate[(int) point.x][(int) point.y];
	iso_transf(point, &screen, map, zoom);
	if (check_in_screen(screen, map->win_w, map->win_h) == 0)
		return (0);
	point.x = 0;
	point.y = map->column - 1;
	point.z = map->coordinate[(int) point.x][(int) point.y];
	iso_transf(point, &screen, map, zoom);
	if (check_in_screen(screen, map->win_w, map->win_h) == 0)
		return (0);
	point.x = map->line - 1;
	point.y = 0;
	point.z = map->coordinate[(int) point.x][(int) point.y];
	iso_transf(point, &screen, map, zoom);
	if (check_in_screen(screen, map->win_w, map->win_h) == 0)
		return (0);
	point.y = map->column - 1;
	point.z = map->coordinate[(int) point.x][(int) point.y];
	iso_transf(point, &screen, map, zoom);
	if (check_in_screen(screen, map->win_w, map->win_h) == 0)
		return (0);
	return (1);
}

float	set_zoom(t_map *map)
{
	int		zoom;
	t_vec3	point;
	t_vec3	screen;

	point.x = 0;
	point.y = 0;
	point.z = 0;
	screen.x = 0;
	screen.y = 0;
	screen.z = 0;
	zoom = 50;
	while (zoom > 1)
	{
		if (check_4_corner_in_screen(zoom, point, screen, map) == 1)
			break ;
		zoom--;
	}
	return ((float)zoom);
}
