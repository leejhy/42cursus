/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:26:41 by junhylee          #+#    #+#             */
/*   Updated: 2024/03/26 13:19:25 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_delta_dist(t_vec *vecs, t_ray *rays)
{
	if (vecs->raydir_y == 0)
		rays->delta_dist_x = 0;
	else
	{
		if (vecs->raydir_x == 0)
			rays->delta_dist_x = 1;
		else
			rays->delta_dist_x = fabs(1 / vecs->raydir_x);
	}
	if (vecs->raydir_x == 0)
		rays->delta_dist_y = 0;
	else
	{
		if (vecs->raydir_y == 0)
			rays->delta_dist_y = 1;
		else
			rays->delta_dist_y = fabs(1 / vecs->raydir_y);
	}
}

void	set_side_dist(t_info *info, t_vec *vecs, t_ray *rays)
{
	if (vecs->raydir_x < 0)
	{
		rays->step_x = -1;
		rays->side_dist_x = (vecs->pos_x - info->map_x) * rays->delta_dist_x;
	}
	else
	{
		rays->step_x = 1;
		rays->side_dist_x = (info->map_x + 1.0 - vecs->pos_x) \
							* rays->delta_dist_x;
	}
	if (vecs->raydir_y < 0)
	{
		rays->step_y = -1;
		rays->side_dist_y = (vecs->pos_y - info->map_y) * rays->delta_dist_y;
	}
	else
	{
		rays->step_y = 1;
		rays->side_dist_y = (info->map_y + 1.0 - vecs->pos_y) \
							* rays->delta_dist_y;
	}
}

t_ray	*set_ray(t_info *info, t_vec *vecs, int x)
{
	t_ray	*rays;

	rays = malloc(sizeof(t_ray));
	if (!rays)
		exit(1);
	info->map_x = (int)(vecs->pos_x);
	info->map_y = (int)(vecs->pos_y);
	set_move_vectors(vecs, x);
	set_delta_dist(vecs, rays);
	set_side_dist(info, vecs, rays);
	return (rays);
}

t_tex	*set_tex(t_ray *rays, t_vec *vecs)
{
	t_tex	*tex;

	tex = malloc(sizeof(t_tex));
	if (!tex)
		exit(1);
	if (rays->side == WALL_X)
		tex->wall_x = vecs->pos_y + rays->perp_wall_dist * vecs->raydir_y;
	else
		tex->wall_x = vecs->pos_x + rays->perp_wall_dist * vecs->raydir_x;
	tex->wall_x -= floor(tex->wall_x);
	tex->texture_x = (int)(tex->wall_x * (double)TEXTURE_WIDTH);
	if (rays->side == WALL_X && vecs->raydir_x > 0)
		tex->texture_x = TEXTURE_WIDTH - tex->texture_x - 1;
	if (rays->side == WALL_Y && vecs->raydir_y < 0)
		tex->texture_x = TEXTURE_WIDTH - tex->texture_x - 1;
	tex->step = 1.0 * TEXTURE_HEIGHT / rays->line_height;
	tex->texture_pos = (rays->start_pixel - \
						(HEIGHT / 2 + rays->line_height / 2)) * tex->step;
	tex->texture_y = 0;
	return (tex);
}

void	set_wallsize(t_ray *rays)
{
	rays->line_height = (int)(HEIGHT / rays->perp_wall_dist);
	rays->start_pixel = HEIGHT / 2 - rays->line_height / 2;
	if (rays->start_pixel < 0)
		rays->start_pixel = 0;
	rays->end_pixel = HEIGHT / 2 + rays->line_height / 2;
}
