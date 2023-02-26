/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:54:09 by agonelle          #+#    #+#             */
/*   Updated: 2023/02/26 09:25:51 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	_init_windows_and_image(t_vars *vars, t_img_dt *image, t_map *map)
{
	image->win_w = map->win_w;
	image->win_h = map->win_h;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, image->win_w, image->win_h, "FdF");
	image->img = mlx_new_image(vars->mlx, map->win_w, map->win_h);
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,
			&image->line_lth, &image->endian);
}

static void	_set_background_color(t_img_dt *image, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < image->win_w)
	{
		j = 0;
		while (j < image->win_h)
		{
			pixel_2img(image, i, j, color);
			j++;
		}
		i++;
	}
}

int	fdf_core(t_map *map)
{
	t_vars		vars;
	t_img_dt	img;

	_init_windows_and_image(&vars, &img, map);
	_set_background_color(&img, 0x0041B3A3);
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
