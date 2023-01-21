/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_get_map_height_width.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:01:35 by agonelle          #+#    #+#             */
/*   Updated: 2023/01/21 12:01:42 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_word(char *str, char sep)
{
	int	i;
	int	count_sep;

	if (str == NULL)
		set_errno_and_return(EINVAL, -1);
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

void	get_map_height_and_width(int fd, int *val_height, int *val_width)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		set_errno_and_exit(EINVAL, "get_map_height_and_width-Invalid_map", -1);
	*val_height = 0;
	*val_width = count_word(line, ' ');
	if (val_width == 0)
	{
		free(line);
		close (fd);
		set_errno_and_exit(EINVAL, "get_map_height_and_width-Invalid_map", -1);
	}
	while (line && (count_word(line, ' ') == *val_width))
	{
		free(line);
		line = get_next_line(fd);
		(*val_height)++;
	}
	if (line && count_word(line, ' ') != *val_width)
	{
		free(line);
		set_errno_and_exit(EINVAL, "get_map_height_and_width-Invalid_map", -1);
	}
}
