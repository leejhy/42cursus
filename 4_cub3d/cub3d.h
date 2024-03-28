/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:21:24 by inghwang          #+#    #+#             */
/*   Updated: 2024/03/26 18:05:20 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include "./gnl/get_next_line.h"

# define WIDTH 1152.0
# define HEIGHT 768.0
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64
# define WEIGHT 0.1
# define WALL_X 0
# define WALL_Y 1

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef enum e_wall_direction
{
	NORTH = 5,
	SOUTH,
	WEST,
	EAST
}	t_wall_direction;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		**wall_north;
	int		**wall_south;
	int		**wall_west;
	int		**wall_east;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_rgb;

typedef struct s_wall
{
	char	**data;
	char	*str;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		*north_addr;
	int		*south_addr;
	int		*west_addr;
	int		*east_addr;
}	t_wall;

typedef struct s_vec
{
	double	dir_x;
	double	dir_y;
	double	pos_x;
	double	pos_y;
	double	plane_x;
	double	plane_y;
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
}	t_vec;

typedef struct s_ray
{
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		side;
	int		line_height;
	int		start_pixel;
	int		end_pixel;
}	t_ray;

typedef struct s_tex
{
	double	texture_pos;
	int		texture_x;
	int		texture_y;
	double	wall_x;
	double	step;
}	t_tex;

typedef struct s_info
{
	char	**map;
	t_wall	*wall;
	t_data	*pixel_img;
	t_vars	*vars;
	t_vec	*vecs;
	t_tex	*tex;
	t_rgb	*floor_rgb;
	t_rgb	*ceiling_rgb;
	int		map_x;
	int		map_y;
	int		camera_x;
	void	*north;
	void	*south;
	void	*west;
	void	*east;
	char	*floor;
	char	*ceiling;
	int		row;
	int		col;
	int		user_y;
	int		user_x;
	char	direction;
}	t_info;

/* main.c */
void	frees(t_info *info);

/* img_make.c */
void	img_make(t_info *info, t_wall *wall, t_data *img, t_vars *vars);

/* info_make.c */
void	info_make(t_wall *wall, t_info *info);

/* map_check.c */
void	map_check(t_info *info);

/* wall_make.c */
void	wall_make(t_wall *wall, t_info *info, int argc, char *argv[]);

/* finish.c */
int		space_check(char c);
void	wall_free(t_wall *wall);
void	info_free(t_info *info);
void	error(void *str, char *message);

/* set_vectors.c */
void	set_vectors(t_info *info);
void	set_dir_vector(t_info *info, t_vec *vecs);
void	rotate_vectors(double *old_vec_x, double *old_vec_y, double angle);
void	set_move_vectors(t_vec *vecs, int x);

/* hook.c */
int		exit_hook(t_info *info);
void	vars_img_init(t_vars *vars, t_data *img);
int		create_trgb(int t, int r, int g, int b);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		key_press(int keycode, t_info *info);

/* control_move.c */
void	control_move(t_info *info, int key_code);
void	player_move(t_info *info, t_vec *vecs, int key_code);
void	rotate_view(t_vec *vecs, int key_code);
int		possible_check(t_info *info, double x_weight, double y_weight);

/* write_pixel.c */
void	write_sky_ground(int x, t_info *info);
t_rgb	*make_rgb(char *str);

/* raycasting.c */
void	run_raycasting(t_info *info, t_vec *vecs);
void	run_dda(t_info *info, t_vec *vecs, t_ray *rays, int hit);
void	put_wall_image(t_info *info, int x, int y, int flag);
void	write_walls(int x, t_info *info, t_ray *rays, t_tex *tex);

/* raycasting_utils.c */
void	set_delta_dist(t_vec *vecs, t_ray *rays);
void	set_side_dist(t_info *info, t_vec *vecs, t_ray *rays);
t_ray	*set_ray(t_info *info, t_vec *vecs, int x);
t_tex	*set_tex(t_ray *rays, t_vec *vecs);
void	set_wallsize(t_ray *rays);

#endif
