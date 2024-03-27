/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:40:04 by junhylee          #+#    #+#             */
/*   Updated: 2024/03/26 13:18:07 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rotate_view(t_vec *vecs, int key_code)
{
	if (key_code == 123)
	{
		rotate_vectors(&vecs->dir_x, &vecs->dir_y, -2);
		rotate_vectors(&vecs->plane_x, &vecs->plane_y, -2);
	}
	else if (key_code == 124)
	{
		rotate_vectors(&vecs->dir_x, &vecs->dir_y, 2);
		rotate_vectors(&vecs->plane_x, &vecs->plane_y, 2);
	}
}

int	possible_check(t_info *info, double x_weight, double y_weight)
{
	t_vec	*vecs;
	int		y;
	int		x;

	vecs = info->vecs;
	x = vecs->pos_x + x_weight * WEIGHT - 0.2;
	y = vecs->pos_y + y_weight * WEIGHT - 0.2;
	if ((info->map)[y][x] == '1')
		return (0);
	x = vecs->pos_x + x_weight * WEIGHT + 0.2;
	y = vecs->pos_y + y_weight * WEIGHT - 0.2;
	if ((info->map)[y][x] == '1')
		return (0);
	x = vecs->pos_x + x_weight * WEIGHT - 0.2;
	y = vecs->pos_y + y_weight * WEIGHT + 0.2;
	if ((info->map)[y][x] == '1')
		return (0);
	x = vecs->pos_x + x_weight * WEIGHT + 0.2;
	y = vecs->pos_y + y_weight * WEIGHT + 0.2;
	if ((info->map)[y][x] == '1')
		return (0);
	vecs->pos_x += x_weight * WEIGHT;
	vecs->pos_y += y_weight * WEIGHT;
	return (1);
}

void	player_move(t_info *info, t_vec *vecs, int key_code)
{
	if (key_code == 13)
	{
		if (!possible_check(info, vecs->dir_x, vecs->dir_y))
			return ;
	}
	else if (key_code == 0)
	{
		if (!possible_check(info, -vecs->plane_x, -vecs->plane_y))
			return ;
	}
	else if (key_code == 1)
	{
		if (!possible_check(info, -vecs->dir_x, -vecs->dir_y))
			return ;
	}
	else if (key_code == 2)
	{
		if (!possible_check(info, vecs->plane_x, vecs->plane_y))
			return ;
	}
}

void	control_move(t_info *info, int key_code)
{
	t_vec	*vecs;

	vecs = info->vecs;
	player_move(info, vecs, key_code);
	mlx_destroy_image(info->vars->mlx, info->pixel_img->img);
	info->pixel_img->img = mlx_new_image(info->vars->mlx, WIDTH, HEIGHT);
	info->pixel_img->addr = mlx_get_data_addr(info->pixel_img->img, \
							&info->pixel_img->bits_per_pixel,
			&info->pixel_img->line_length, &info->pixel_img->endian);
	rotate_view(vecs, key_code);
	run_raycasting(info, vecs);
	mlx_put_image_to_window(info->vars->mlx, info->vars->win, \
							info->pixel_img->img, 0, 0);
}
