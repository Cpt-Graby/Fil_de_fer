/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:54:09 by agonelle          #+#    #+#             */
/*   Updated: 2023/02/14 00:58:06 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	check_file_and_parse(char *path, t_map *map)
{
	if (!check_extension_filename(path))
	{
		errno = EINVAL;
		perror("main.c - fdf_core");
		exit(-1);
	}
	if (!main_file_parser(path, map))
		exit(-1);
	/*
	for (int i = 0; i < map->line; i++)
	{
		for (int j = 0; j < map->column; j++)
		{
			if(map->coordinate[i][j] == 0)
			{
				printf(" %.2f ", map->coordinate[i][j]);
			}
			else
			{
				printf("%.2f ", map->coordinate[i][j]);
			}
		}
		printf("\n");
	}
	*/
}

int	fdf_core(t_map *map)
{
	t_vars		vars;
	t_img_dt	img;

	(void)vars;
	map->win_h = 600;
	map->win_w = 800;
	img.win_h = map->win_h;
	img.win_w = map->win_w;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, map->win_w, map->win_h, "FdF");
	img.img = mlx_new_image(vars.mlx, map->win_h, map->win_h);
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
		check_file_and_parse(argv[1], &map_data);
		err = fdf_core(&map_data);
	}
	else
	{
		errno = E2BIG;
		perror("main.c - main");
	}
	return (err);
}
