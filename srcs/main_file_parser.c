/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_file_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:59:56 by agonelle          #+#    #+#             */
/*   Updated: 2023/01/20 21:23:06 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_word(char *str, char sep)
{
	int	i;
	int	count_sep;

	i = 0;
	count_sep = 0;
	while (str[i] == sep && str[i])
		i++;
	if (!str[i])
		return (count_sep);
	while (str[i])
	{
		if (str[i] == sep)
		{
			count_sep++;
			while (str[i] == sep && str[i])
				i++;
		}
		else
			i++;
	}
	return (count_sep + 1);
}

static void	get_map_height_and_width(int fd, int *val_height, int *val_width)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
	{
		perror("get_val_height_and_wight - main_file_parcer.c");
		exit(-1);
	}
	*val_height = 0;
	*val_width = count_word(line, ' ');
	if (val_width == 0)
	{
		perror("No arguments in first line");
		free(line);
		close (fd);
		exit (-1);
	}
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		(*val_height)++;
	}
}

int	main_file_parser(char *path, t_map *map)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror("main_file_parser.c");
		return (0);
	}
	get_map_height_and_width(fd, &(map->line), &(map->column));
	if (close (fd) == -1)
	{
		perror("main_file_parser.c");
		return (0);
	}
	return (1);
}
