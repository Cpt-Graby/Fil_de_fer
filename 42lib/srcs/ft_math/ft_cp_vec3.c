/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cp_vec3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 21:52:58 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/21 21:54:21 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_cp_vec3(t_vec3 point, t_vec3 *new_vec)
{
	new_vec->x = point.x;
	new_vec->y = point.y;
	new_vec->z = point.z;
}
