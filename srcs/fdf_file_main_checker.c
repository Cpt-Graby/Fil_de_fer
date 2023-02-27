/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_file_main_checker.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:53:51 by agonelle          #+#    #+#             */
/*   Updated: 2023/02/27 12:35:42 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_file_and_extract_map_data(char *path, t_map *map)
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
	map->zoom = set_zoom(map);
}

int	check_extension_filename(char *path)
{
	int		i;

	i = ft_strlen(path);
	if (i <= 4)
		return (0);
	else if (path[i - 1] == 'f' && path[i - 2] == 'd' && path[i - 3] == 'f'
		&& path[i - 4] == '.')
		return (1);
	else
		return (0);
}
