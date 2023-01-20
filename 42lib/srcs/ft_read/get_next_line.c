/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:08:00 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/29 17:51:31 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*get_next_line(int fd)
{
	static char	*rest[4097];
	char		*line;

	if (fd < 0)
		return (NULL);
	rest[fd] = update_buff(fd, rest[fd]);
	if (!rest[fd])
	{
		free (rest[fd]);
		return (NULL);
	}
	line = get_res_line(rest[fd]);
	rest[fd] = update_nextl(rest[fd]);
	return (line);
}

char	*update_buff(int fd, char *rest)
{
	int		count;
	int		flag;
	char	sol[BUFFER_SIZE + 1];

	if (!rest)
		rest = ft_calloc(sizeof(*rest), 1);
	if (!rest)
		return (NULL);
	count = 1;
	flag = get_next_c(rest, '\n');
	while (count > 0 && !flag)
	{
		count = read(fd, sol, BUFFER_SIZE);
		if (count == -1)
		{
			free(rest);
			return (NULL);
		}
		sol[count] = '\0';
		rest = get_transf(sol, rest);
		if (!rest)
			return (NULL);
		flag = get_next_c(rest, '\n');
	}
	return (rest);
}

char	*get_transf(char *s1, char *rest)
{
	char	*tmp;

	tmp = get_join(rest, s1);
	free(rest);
	if (!tmp)
		return (NULL);
	return (tmp);
}

char	*get_res_line(char *buff)
{
	char	*str;
	int		ind;

	if (buff[0] == '\0')
		return (NULL);
	ind = 0;
	while (buff[ind] != '\0' && buff[ind] != '\n')
		ind++;
	str = get_ndup(buff, ind + 1);
	return (str);
}

char	*update_nextl(char *buff)
{
	char	*tmp;
	int		ind;
	int		i;

	ind = 0;
	while (buff[ind] != '\0' && buff[ind] != '\n')
		ind++;
	if (buff[ind] == '\0')
	{
		free(buff);
		return (NULL);
	}
	tmp = ft_calloc(sizeof(*tmp), get_len(buff) - ind + 1);
	i = 0;
	while (buff[++ind] != '\0')
	{
		tmp[i] = buff[ind];
		i++;
	}
	free(buff);
	return (tmp);
}
