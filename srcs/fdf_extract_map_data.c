/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_extract_map_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:32:09 by agonelle          #+#    #+#             */
/*   Updated: 2023/02/17 10:34:55 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_map_data_from_fd(int fd, t_map *map)
{
	char	*line;
	int		i;

	map->coordinate = create_float_tab(map->column, map->line);
	line = get_next_line(fd);
	if (!line)
		syscall_error_exit("check_and_get_map_data", -1);
	i = 0;
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
	char	*start_ascii_number;

	y = 0;
	start_ascii_number = string;
	while (*start_ascii_number == ' ')
		start_ascii_number++;
	while (y < max_col)
	{
		tab[*index][y] = (float) ft_atoi(start_ascii_number);
		set_next_word(&start_ascii_number, ' ');
		y++;
	}
	start_ascii_number = string;
	*index = *index + 1;
}

void	set_next_word(char **index_string, char sep)
{
	char	*pointer_next_word;

	pointer_next_word = *index_string;
	while (*pointer_next_word != sep && *pointer_next_word != '\0')
		pointer_next_word++;
	while (*pointer_next_word == sep)
		pointer_next_word++;
	*index_string = pointer_next_word;
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
