/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:18:50 by agonelle          #+#    #+#             */
/*   Updated: 2023/02/25 22:14:20 by agonelle         ###   ########.fr       */
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
	t_vec3	barycenter;
	int		win_w;
	int		win_h;
	float	**coordinate;
}	t_map;

//main.c
int		main(int argc, char **argv);
int		fdf_core(t_map *map);
int		transfer_2_img(t_map *map, t_img_dt *img);

//fdf_main_file_parser.c
int		main_file_parser(char *path, t_map *map);

//fdf_extract_map_data_from_fd.c
int		extract_map_data_from_fd(int fd, t_map *map);
void	get_data_from_line(char *string, int *index, float **tab, int max_col);
void	set_next_word(char **index_string, char sep);
float	**create_float_tab(int column, int line);

//file_check_entension.c
int		check_extension_filename(char *path);

//fdf_error.c
int		syscall_error_return(char *msg, int value_2_return);
void	syscall_error_exit(char *msg, int value_2_exit);
int		set_errno_and_return(int error, int value_2_return);
void	set_errno_and_exit(int error, char *msg, int value_2_return);

//get_map_height_width.c
void	get_map_height_and_width(int fd, int *val_height, int *val_width);
int		count_word(char *str, char sep);
//
//utils
int		check_line(char *str);
void	free_t_line(t_line *line, int len);
int		vec3_in_screen(t_vec3 vec, int max_L, int max_H);
void	set_window_size(t_map *map);
float	set_zoom(t_map *map);

//Keyevent
int		close_win(int keycode, t_vars *vars);
int		print_key(int keycode, t_vars *vars);

//fdf_projection_to_screen.c
void	transfer_2_screen(t_map *map, t_img_dt *data);
void	column_2_img(t_map *map, t_img_dt *data, int x);
void	line_2_img(t_map *map, t_img_dt *data, int x);
void	iso_transf(t_vec3 point, t_vec3 *screen, t_map *map);
void	pixel_2img(t_img_dt *data, int x, int y, int color);

// fdf_bresenham.c
void	set_var(t_vec2 *e, t_vec2 *del, t_vec2 *d, t_vec2 *inc);
void	case_dx_dy(t_vec2 e, t_vec3 p1, t_vec3 p2, t_img_dt *data);
void	case_dy_dx(t_vec2 e, t_vec3 p1, t_vec3 p2, t_img_dt *data);
void	draw_line(t_vec3 p1, t_vec3 p2, t_img_dt *data);

#endif
