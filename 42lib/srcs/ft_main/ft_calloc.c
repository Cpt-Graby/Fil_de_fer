/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:27:21 by agonelle          #+#    #+#             */
/*   Updated: 2022/10/12 16:49:58 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	res = malloc(size * nmemb);
	if (!res)
		return (NULL);
	ft_bzero(res, size * nmemb);
	return (res);
}
