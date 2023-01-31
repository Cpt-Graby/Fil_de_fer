/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:54:09 by agonelle          #+#    #+#             */
/*   Updated: 2023/01/31 01:42:39 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_core(char *path)
{
	t_map		map;
	t_vars		vars;
	t_img_dt	img;

	if (!check_extension_filename(path))
	{
		errno = EINVAL;
		perror("main.c - fdf_core");
		exit(-1);
	}
	if (!main_file_parser(path, &map))
		exit(-1);
	vars.mlx = mlx_init();
	img.win_h = 800;
	img.win_w = 800;
	vars.win = mlx_new_window(vars.mlx, map.win_w, map.win_h, "FdF");
	img.img = mlx_new_image(vars.mlx, map.win_h, map.win_h);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lth,
			&img.endian);
	//transfer_2_screen(&map, &img);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 17, 0, close_win, &vars);
	mlx_key_hook(vars.win, print_key, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	int	err;

	err = 0;
	if (argc == 1)
	{
		errno = EINVAL;
		perror("main.c - main");
	}
	else if (argc == 2)
		err = fdf_core(argv[1]);
	else
	{
		errno = E2BIG;
		perror("main.c - main");
	}
	return (err);
}
