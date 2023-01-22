/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main_file_parser.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:59:56 by agonelle          #+#    #+#             */
/*   Updated: 2023/01/22 12:11:00 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_next_word(char **index_string, char sep)
{
	char	*next;

	next = *index_string;
	while (*next != sep)
		next++;
	while (*next == sep)
		next++;
	index_string = &next;
}

void	get_data_from_line(char *string, int *index, int *tab)
{
	int		i;
	char	*start_number;

	i = *index;
	start_number = string;
	while (*start_number == ' ')
		start_number++;
	while (*start_number != '\0')
	{
		tab[i] = ft_atoi(start_number);
		set_next_word(&start_number, ' ');
		i++;
	}
}

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
	map->tab_coord = malloc(sizeof(int) * nbr_elem);
	if (!map->tab_coord)
	{
		free(line);
		syscall_error_return("check_and_get_map_data", 0);
	}
	while (line)
	{
		get_data_from_line(line, &i, map->tab_coord);
		free(line);
		if (i < nbr_elem)
			line = get_next_line(fd);
	}
	if (i < nbr_elem)
		syscall_error_return("Some element has not been taken", 0);
	return (1);
}

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
	tmp = get_map_data_from_fd(fd, map);
	if (tmp == 0 && errno != -1)
		syscall_error_return("main_file_parser", 0);
	if (tmp == 0)
		return (0);
	if (close (fd) == -1)
		syscall_error_return("main_file_parser", 0);
	return (1);
}
