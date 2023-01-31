/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_get_coordinate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:44:10 by agonelle          #+#    #+#             */
/*   Updated: 2023/01/31 01:14:19 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_map_data_from_fd(int fd, t_map *map)
{
	char	*line;
	int		i;

	i = 0;
	map->coordinate = create_float_tab(map->column, map->line);
	line = get_next_line(fd);
	if (!line)
		syscall_error_exit("check_and_get_map_data", -1);
	while (i < map->line)
	{
		get_data_from_line(line, &i, map->coordinate, map->column);
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}

void	get_data_from_line(char *string, int *index, float **tab, int max_col)
{
	int		y;
	char	*start_number;

	y = 0;
	start_number = string;
	while (*start_number == ' ')
		start_number++;
	while (y < max_col)
	{
		tab[*index][y] = (float) ft_atoi(start_number);
		set_next_word(&start_number, ' ');
		y++;
	}
	*index = *index + 1;
}

void	set_next_word(char **index_string, char sep)
{
	char	*next;

	next = *index_string;
	while (*next != sep)
		next++;
	while (*next == sep)
		next++;
	*index_string = next;
}

float	**create_float_tab(int column, int line)
{
	float	**new_tab;
	int		i;

	new_tab = malloc(sizeof(*new_tab) * line);
	if (!new_tab)
		syscall_error_exit("create_float_tab - 2nd malloc", -1);
	i = 0;
	while (i < line)
	{
		new_tab[i] = malloc(sizeof(*new_tab[i]) * column);
		if (!new_tab[i])
			syscall_error_exit("create_float_tab - 2nd malloc", -1);
		i++;
	}
	return (new_tab);
}
