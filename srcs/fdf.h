/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:18:50 by agonelle          #+#    #+#             */
/*   Updated: 2023/01/20 21:04:09 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "../mlx.h"
# include "../42lib/libft.h"

typedef struct s_img_dt {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lth;
	int		endian;
	int		win_w;
	int		win_h;
}	t_img_dt;

typedef struct s_vars_w{
	void		*mlx;
	void		*win;
	t_img_dt	*pic;
}	t_vars;

typedef struct s_line {
	t_vec3	*tab_pts;
}	t_line;

typedef struct s_map {
	char	*path;
	int		line;
	int		column;
	int		max_h;
	int		win_w;
	int		win_h;
	t_line	*tab_line;
}	t_map;

//main.c
int		main(int argc, char **argv);
int		fdf_core(char *path);

//main_file_parser.c
int		main_file_parser(char *path, t_map *map);

//file_check_entension.c
int		check_extension_filename(char *path);

//file_2_data.c
int		map_parser(int fd, t_map *map);
void	get_first_info_parser(char *line, t_map *map);
t_line	*get_next_pts_line(t_map *map, char **tab);
int		new_line_2_tab(char *line, t_map *map);

//utils
int		check_extension(char *path);
int		check_line(char *str);
void	free_t_line(t_line *line, int len);
int	vec3_in_screen(t_vec3 vec, int max_L, int max_H);
void	set_window_size(t_map *map);
float	set_zoom(t_map *map);

//Keyevent
int		close_win(int keycode, t_vars *vars);
int		print_key(int keycode, t_vars *vars);

//fdf_mlx.c
void	transfer_2_screen(t_map *map, t_img_dt *data);
void	column_2_img(t_map *map, t_img_dt *data, int x);
void	line_2_img(t_map *map, t_img_dt *data, int x);
void	iso_transf(t_vec3 point, t_vec3 *screen, t_map *map);
void	pixel_2img(t_img_dt *data, int x, int y, int color);

// fdf_bresenham.c
void	case_dx_dy(t_vec2 e, t_vec3 p1, t_vec3 p2, t_img_dt *data);
void	case_dy_dx(t_vec2 e, t_vec3 p1, t_vec3 p2, t_img_dt *data);
void	draw_line(t_vec3 p1, t_vec3 p2, t_img_dt *data);

#endif
