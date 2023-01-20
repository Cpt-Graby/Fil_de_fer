/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:02:56 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/21 21:54:13 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

typedef struct s_vec3 {
	float	x;
	float	y;
	float	z;
}	t_vec3;

typedef struct s_vec2 {
	int	x;
	int	y;
}	t_vec2;

int		ft_val_in_r(int v, int min, int max);
void	print_vec3(t_vec3 vec);
void	ft_cp_vec3(t_vec3 point, t_vec3 *new_vec);
#endif
