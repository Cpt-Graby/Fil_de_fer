/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_file_extension_checker.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:53:51 by agonelle          #+#    #+#             */
/*   Updated: 2023/01/20 21:06:09 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
