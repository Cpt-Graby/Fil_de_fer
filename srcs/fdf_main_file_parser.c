/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main_file_parser.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:59:56 by agonelle          #+#    #+#             */
/*   Updated: 2023/01/21 12:35:21 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_map_data_from_fd(int fd, t_map *map)
{
	char	*line;
	int		nbr_elem;
	int		i;

	i = 0;
	nbr_elem = map->line * map->column;
	line = get_next_line(fd);
	if (!line)
		syscall_error_return("check_and_get_map_data", 0);
	map->tab_line = malloc(sizeof(int) * nbr_elem);
	if (!map->tab_line)
	{
		free(line);
		syscall_error_return("check_and_get_map_data", 0);
	}
	while (line)
	{
		get_data_from_line(line, &i, &map->tab_line);
		free(line);
		line = get_next_line(fd);
		if (!line)
			return (-1); // TODO FREE DATA
	}
	return (1);
}

int	main_file_parser(char *path, t_map *map)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		syscall_error_return("main_file_parser", 0);
	get_map_height_and_width(fd, &(map->line), &(map->column));
	if (close(fd) == -1)
		syscall_error_return("main_file_parser", 0);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		syscall_error_return("main_file_parser", 0);
	if (get_map_data_from_fd(fd, map) == 0)
		return (0);
	if (close (fd) == -1)
		syscall_error_return("main_file_parser", 0);
	return (1);
}
