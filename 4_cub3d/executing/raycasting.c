/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:15:30 by junhylee          #+#    #+#             */
/*   Updated: 2024/03/26 15:15:43 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	run_dda(t_info *info, t_vec *vecs, t_ray *rays, int hit)
{
	while (hit == 0)
	{
		if (rays->side_dist_x < rays->side_dist_y)
		{
			rays->side_dist_x += rays->delta_dist_x;
			info->map_x += rays->step_x;
			rays->side = WALL_X;
		}
		else
		{
			rays->side_dist_y += rays->delta_dist_y;
			info->map_y += rays->step_y;
			rays->side = WALL_Y;
		}
		if (info->map[info->map_y][info->map_x] == '1')
			hit = 1;
	}
	if (rays->side == WALL_X)
		rays->perp_wall_dist = \
		((info->map_x + (1 - rays->step_x) / 2) - vecs->pos_x) / vecs->raydir_x;
	else
		rays->perp_wall_dist = \
		(info->map_y - vecs->pos_y + (1 - rays->step_y) / 2) / vecs->raydir_y;
	set_wallsize(rays);
}

void	put_wall_image(t_info *info, int x, int y, int flag)
{
	char	*dst;
	t_data	*img;
	t_tex	*tex;

	tex = info->tex;
	img = info->pixel_img;
	if (x < WIDTH && y < HEIGHT)
	{
		dst = img->addr + \
				(y * img->line_length + x * (img->bits_per_pixel / 8));
		if (flag == NORTH)
			*(unsigned int *)dst = \
			img->wall_north[tex->texture_y][tex->texture_x];
		else if (flag == SOUTH)
			*(unsigned int *)dst = \
			img->wall_south[tex->texture_y][tex->texture_x];
		else if (flag == WEST)
			*(unsigned int *)dst = \
			img->wall_west[tex->texture_y][tex->texture_x];
		else if (flag == EAST)
			*(unsigned int *)dst = \
			img->wall_east[tex->texture_y][tex->texture_x];
	}
}

void	write_walls(int x, t_info *info, t_ray *rays, t_tex *tex)
{
	t_vec	*vecs;
	int		y;

	y = rays->start_pixel;
	vecs = info->vecs;
	while (y < rays->end_pixel)
	{
		tex->texture_y = (int)tex->texture_pos & (TEXTURE_HEIGHT - 1);
		tex->texture_pos += tex->step;
		if (rays->side == WALL_X)
		{
			if (vecs->raydir_x > 0)
				put_wall_image(info, x, y, WEST);
			else
				put_wall_image(info, x, y, EAST);
		}
		else
		{
			if (vecs->raydir_y > 0)
				put_wall_image(info, x, y, NORTH);
			else
				put_wall_image(info, x, y, SOUTH);
		}
		y++;
	}
}

void	run_raycasting(t_info *info, t_vec *vecs)
{
	t_ray	*rays;
	int		x;

	x = 0;
	while (x < WIDTH)
	{
		rays = set_ray(info, vecs, x);
		run_dda(info, vecs, rays, 0);
		write_sky_ground(x, info);
		info->tex = set_tex(rays, vecs);
		write_walls(x, info, rays, info->tex);
		free(info->tex);
		free(rays);
		x++;
	}
}
