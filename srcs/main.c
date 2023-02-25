/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:54:09 by agonelle          #+#    #+#             */
/*   Updated: 2023/02/25 22:03:57 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_barycenter(t_map *map)
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

static void	check_file_and_extract_map_data(char *path, t_map *map)
{
	if (!check_extension_filename(path))
	{
		errno = EINVAL;
		perror("main.c - fdf_core");
		exit(-1);
	}
	if (!main_file_parser(path, map))
		exit(-1);
	get_barycenter(map);
	map->win_h = 600;
	map->win_w = 800;
}

int	fdf_core(t_map *map)
{
	t_vars		vars;
	t_img_dt	img;

	img.win_w = map->win_w;
	img.win_h = map->win_h;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, img.win_w, img.win_h, "FdF");
	img.img = mlx_new_image(vars.mlx, map->win_w, map->win_h);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lth,
			&img.endian);
	transfer_2_screen(map, &img);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 17, 0, close_win, &vars);
	mlx_key_hook(vars.win, print_key, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	int		err;
	t_map	map_data;

	err = 0;
	if (argc == 1)
	{
		errno = EINVAL;
		perror("main.c - main");
	}
	else if (argc == 2)
	{
		check_file_and_extract_map_data(argv[1], &map_data);
		err = fdf_core(&map_data);
	}
	else
	{
		errno = E2BIG;
		perror("main.c - main");
	}
	return (err);
}
