/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:34:51 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/08 11:36:48 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READ_H
# define FT_READ_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 200
# endif

char	*get_next_line(int fd);
char	*update_buff(int fd, char *rest);
char	*update_nextl(char *buff);
char	*get_res_line(char *buff);
char	*get_transf(char *s1, char *rest);
char	*get_join(char *s1, char *s2);
char	*get_ndup(char *s, size_t n);
int		get_next_c(char *s, char c);
int		get_len(char *s);
void	*ft_calloc(size_t nmemb, size_t size);

#endif 
