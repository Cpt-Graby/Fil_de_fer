/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projection_on_screen.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:29:19 by agonelle          #+#    #+#             */
/*   Updated: 2023/02/17 11:59:26 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	transfer_2_screen(t_map *map, t_img_dt *data)
{
	int		x;

	x = 0;
	while (x < map->line)
	{
		line_2_img(map, data, x);
		x++;
	}
	x = 0;
	while (x < map->column)
	{
		column_2_img(map, data, x);
		x++;
	}
}

void	line_2_img(t_map *map, t_img_dt *data, int x)
{
	int		i;
	t_vec3	tmp;
	t_vec3	pt1_sc;
	t_vec3	pt2_sc;

	i = 1;
	tmp.x = i - 1;
	tmp.y = x;
	tmp.z = map->coordinate[x][i - 1];
	while (i < map->column)
	{
		iso_transf(tmp, &pt1_sc, map);
		tmp.x = i;
		tmp.z = map->coordinate[x][i];
		iso_transf(tmp, &pt2_sc, map);
		draw_line(pt1_sc, pt2_sc, data);
		i++;
	}
}

void	column_2_img(t_map *map, t_img_dt *data, int x)
{
	int		i;
	t_vec3	tmp;
	t_vec3	pt1_sc;
	t_vec3	pt2_sc;

	i = 1;
	tmp.x = x;
	tmp.y = i - 1;
	tmp.z = map->coordinate[i - 1][x];
	while (i < map->line)
	{
		iso_transf(tmp, &pt1_sc, map);
		tmp.y = i;
		tmp.z = map->coordinate[i][x];
		iso_transf(tmp, &pt2_sc, map);
		draw_line(pt1_sc, pt2_sc, data);
		i++;
	}
}

void	iso_transf(t_vec3 point, t_vec3 *screen, t_map *map)
{
	float	zoom;
	float	y_transf_iso;
	float	x_transf_iso;
	float	trsx;
	float	trsy;

//	zoom = 1.0 * set_zoom(map);
	zoom = 15;
//	trsx = ((float)map->column / 2) * (-1);
	trsx = (map->barycenter.x - map->barycenter.y) * cos(0.523599);
//	trsy = ((float)map->line / 2) * (-1);
	trsy = (map->barycenter.z
			+ (map->barycenter.x + map->barycenter.y)) * sin(0.523599);
	x_transf_iso = (point.x - point.y) * cos(0.523599);
	y_transf_iso = ((-1) * point.z + (point.x + point.y)) * sin(0.523599);
	screen->x = (float)map->win_w / 2 + (x_transf_iso + trsx) * zoom;
	screen->y = (float)map->win_h / 2 + (y_transf_iso - trsy) * zoom;
	screen->z = point.z;
}

void	pixel_2img(t_img_dt *data, int x, int y, int color)
{
	char	*dst;

	if ((x > 0 && x < data->win_h) && (y > 0 && y < data->win_w))
	{
	dst = data->addr + (y * data->line_lth + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	}
}
