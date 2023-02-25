/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main_file_parser.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:59:56 by agonelle          #+#    #+#             */
/*   Updated: 2023/02/25 22:12:25 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main_file_parser(char *path, t_map *map)
{
	int	fd;
	int	tmp;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		syscall_error_return("main_file_parser", 0);
	get_map_height_and_width(fd, &(map->line), &(map->column));
	if (close(fd) == -1)
		syscall_error_return("main_file_parser", 0);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		syscall_error_return("main_file_parser", 0);
	tmp = extract_map_data_from_fd(fd, map);
	if (tmp == 0 && errno != -1)
		syscall_error_return("main_file_parser", 0);
	if (tmp == 0)
		return (0);
	if (close (fd) == -1)
		syscall_error_return("main_file_parser", 0);
	return (1);
}
