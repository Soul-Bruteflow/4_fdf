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

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <mlx.h>
# include "libft.h"
# include "get_next_line.h"

typedef unsigned int	t_ui;
typedef unsigned char	t_ch;

# define USAGE 1
# define LINE 2
# define COLOR 3
# define MALLCHECK 4
# define FCLOSE 5
# define FOPEN 6
# define GNL 7
# define ZERO 8
# define OONE 9
# define TRUE 1
# define FALSE -1

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
** Minilibx struct.
*/
typedef struct			s_mlx
{
	struct s_pixel		***m_pixels;
	void				*mlx_ptr;
	void				*mlx_win;
	void				*mlx_img;
	char				*mlx_str;
	int					*bits;
	int					*size_line;
	int 				*endian;
}						t_mlx;

/*
** File read map struct.
*/
typedef struct			s_map
{
	int 				c;
	int 				r;
	int 				*tmp_z;
	int 				*tmp_color;
	int 				end;
	int 				beg;
	int 				i;
	int 				j;
	int 				ctrl;
	int 				fd;
	size_t				tmp;
	size_t				map_x;
	size_t				map_y;
	size_t				tmp_x1;
	size_t				tmp_y1;
	size_t				tmp_x2;
	size_t				tmp_y2;
	char 				*line;
	char 				**name;
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
** Validation.
*/
void					fdf_validate(t_map *map);
/*
** File conversion to struct.
*/
void					fdf_pixel_malloc(t_map *map, t_mlx *pixel);
void					fdf_pixel_read(t_map *map, t_mlx *pixel);
void					fdf_pixel_color_z(t_map *map, t_mlx *pixel);
int						fdf_pixel_color(t_map *map);
int						ft_ishex(char c);
int						ft_atoi_hex(char *s);
/*
** Draw.
*/
void					fdf_draw(t_map *map, t_mlx *pixel);
#endif
