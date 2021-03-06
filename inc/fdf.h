/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:08:29 by mvlad             #+#    #+#             */
/*   Updated: 2017/03/13 17:08:33 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H

# include <math.h>
# include <fcntl.h>
# include <mlx.h>
# include "libft.h"
# include "get_next_line.h"

# define USAGE 1
# define LINE 2
# define COLOR 3
# define MALLCHECK 4
# define FCLOSE 5
# define FOPEN 6
# define GNL 7
# define ZERO 8
# define OONE 9
# define BIG 10
# define TRUE 1
# define FALSE -1
# define MINZ -100
# define MAXZ 100
# define HEIGHT 900
# define WIDTH 1500

/*
** zeroes
*/
# define RED0 232
# define GREEN0 153
# define BLUE0 25

/*
** positive
*/
# define RED1 238
# define GREEN1 28
# define BLUE1 17

/*
** negative
*/
# define RED2 81
# define GREEN2 39
# define BLUE2 206

/*
** Keys
*/
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define MINUS 27
# define PLUS 24
# define QKEY 12
# define WKEY 13
# define AKEY 0
# define SKEY 1
# define ZKEY 6
# define XKEY 7

/*
** Radians
*/
# define PI 3.14159265358979323846
# define DTR(angleDegrees) (angleDegrees * PI / 180.0)
# define DEGREE 5

/*
** Single pixel data.
*/
typedef struct			s_pixel
{
	float				x;
	float				y;
	float				z;
	int					red;
	int					green;
	int					blue;
	int					alpha;
}						t_pixel;
/*
** Bresenham struct.
*/
typedef struct			s_b
{
	int					dlx;
	int					dly;
	int					snx;
	int					sny;
	int					er;
	int					e2;
	float				i;
	float				i2;
	float				i3;
}						t_b;
/*
** ***m_pixels - holds map coordinates and color
** *ptr - mlx_init(); *win - mlx_new_window();
** *img - mlx_new_image(); *str - mlx_get_data_addr();
** bit - number of bits per pixel; line_sz - size of one line in bits;
** end - endian;
*/
typedef struct			s_mlx
{
	struct s_pixel		***m_pixels;
	struct s_b			*b;
	void				*ptr;
	void				*win;
	void				*img;
	char				*str;
	int					bit;
	int					line_sz;
	int					end;
	int					imgx;
	int					imgy;
	size_t				map_x;
	size_t				map_y;
	int					x1;
	int					y1;
	int					x2;
	int					y2;
	int					r0;
	int					g0;
	int					b0;
	int					r1;
	int					g1;
	int					b1;
	size_t				c;
	size_t				r;
	size_t				total_size;
	int					xcen;
	int					ycen;
	int					wcenx;
	int					wceny;
	int					width;
	int					height;
	int					wxcur;
	int					wycur;
	int					zoom;
	long				bound;
	char				**name;
}						t_mlx;

/*
** File read map struct.
*/
typedef struct			s_map
{
	size_t				c;
	size_t				r;
	int					*tmp_z;
	int					*tmp_color;
	int					end;
	int					beg;
	int					i;
	int					j;
	size_t				ctrl;
	int					fd;
	size_t				tmp;
	size_t				map_x;
	size_t				map_y;
	char				*line;
	char				**name;
}						t_map;

/*
** Error handling.
*/
void					fdf_error(int n);
void					fdf_close_file(t_map *map);
void					fdf_close_line(t_map *map);
void					fdf_open_file(t_map *map);
void					fdf_gnl_error(t_map *map, int i);
void					fdf_nbr_error(t_map *map, size_t i);
/*
** Parsing and validation.
*/
void					fdf_validate(t_map *map);
void					fdf_pixel_malloc(t_map *map, t_mlx *pixel);
void					fdf_pixel_read(t_map *map, t_mlx *pixel);
void					fdf_pixel_color_z(t_map *map);
int						fdf_pixel_color(t_map *map);
void					fdf_my_color(t_map	*map, t_mlx *data);
int						ft_ishex(char c);
int						ft_atoi_hex(char *s);
/*
** Initial run
*/
void					fdf_mlx_init(t_mlx *mlx, t_map *map);
void					fdf_win_setup(t_mlx *mlx);
void					fdf_zoom_auto_plus(t_mlx *mlx);
void					fdf_zoom_auto_minus(t_mlx *mlx);
void					fdf_first_draw(t_mlx *mlx, t_map *map);
/*
** Draw and redraw
*/
void					fdf_draw(t_mlx *pixel);
void					fdf_center_find(t_mlx *data);
void					fdf_center_place(t_mlx *data);
void					fdf_center_current(t_mlx *data);
void					fdf_center_zero(t_mlx *data);
void					fdf_redraw(t_mlx *mlx);
void					fdf_redraw_zoom(t_mlx *mlx);
/*
** UI
*/
void					fdf_ui(t_mlx *mlx);
/*
** Keys, movement, rotation and scale.
*/
int						fdf_key_core(int keycode, t_mlx *data);
void					fdf_move(int kcode, t_mlx *mlx);
void					fdf_zoom(int kcode, t_mlx *mlx);
void					fdf_rotate_x(int kcode, t_mlx *mlx);
void					fdf_rotate_y(int kcode, t_mlx *mlx);
void					fdf_rotate_z(int kcode, t_mlx *mlx);
void					fdf_rotate(int kcode, t_mlx *data);
#endif
