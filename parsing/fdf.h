/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 22:29:56 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/25 21:10:34 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
# include <math.h>
# include "./gnl/get_next_line.h"

// typedef struct s_dda
// {
// 	float	start_x;
// 	float	start_y;
// 	float	dx;
// 	float	dy;
// 	float	dis;
// 	float	inc_x;
// 	float	inc_y;
// }	t_dda;

// typedef struct s_data
// {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }	t_data;

// typedef struct s_vars
// {
// 	void	*mlx;
// 	void	*win;
// }	t_vars;

typedef struct s_xyz
{
	float	x;
	float	y;
	float	z;
}	t_xyz;

typedef struct s_coord
{
	float	offset_x;
	float	offset_y;
	float	height;
	float	width;
	int		col;
	int		row;
	int		gap;
	int		z_gap;
	t_xyz	**xyz_map;
}	t_coord;

//init.c
void	xyz_map_init(t_coord *coord, int **z_map);
void	coord_init(t_coord *coord);
void	rotate_init(t_coord *coord);
//fdf_utils.c
size_t	ft_strlen(char *str);
//rotation.c
void	euler_x(float *old_y, float *old_z, double angle);
void	euler_y(float *old_x, float *old_z, double angle);
void	euler_z(float *old_x, float *old_y, double angle);
//parsing.c
void	filename_f_check(char *str);
int		ft_line_cnt(char *file_name);
int		**parsing(char *file_name, int *col_size, int *row_size);
//read_map.c
int		**read_map(int fd, int line_cnt, int *col_size, int *row_size);
int		**map_to_coordinate(char **map, int x_cnt, int y_cnt);
int		**make_coordinate(int x_cnt, int y_cnt);
char	**get_map(int fd, int *line_cnt);
long long	ft_atoll(const char *str);
//readmap_utils.c
void	check_valid_map(char **map, size_t col_cnt, size_t line_cnt);
int		check_ln(char *str);
int		is_sep(char c, char *sep);
size_t		ft_col_cnt(char *str, char *sep);
//filecheck.c
int		ft_strncmp(char *s1, char *s2, size_t n);
size_t	ft_word_cnt(char *str, char sep);
char	*ft_strdup(char *str, char sep);
void	filename_frees(char **ptr);
void	filename_check(char *str);
//error.c
void	ft_error(int err);
void	args_error(void);
void	malloc_failed(void);
void	file_error(void);
void	map_error(void);
#endif