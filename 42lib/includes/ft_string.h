/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:22:19 by agonelle          #+#    #+#             */
/*   Updated: 2023/02/08 16:12:28 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include "../libft.h"

size_t	ft_maxlstr(char *str1, char *str2);
size_t	ft_lensplit(char **tab);
int		ft_ascii_in_int(char *num_string);
int		ft_ascii_is_number(char *str);

#endif
