/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_vectors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:39:13 by junhylee          #+#    #+#             */
/*   Updated: 2024/03/26 13:21:15 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_dir_vector(t_info *info, t_vec *vecs)
{
	vecs->dir_x = 0;
	vecs->dir_y = 0;
	if (info->direction == 'N')
		vecs->dir_y = -1;
	else if (info->direction == 'S')
		vecs->dir_y = 1;
	else if (info->direction == 'W')
		vecs->dir_x = -1;
	else if (info->direction == 'E')
		vecs->dir_x = 1;
}

void	set_vectors(t_info *info)
{
	t_vec	*vecs;

	vecs = malloc(sizeof(t_vec));
	if (!vecs)
		exit(1);
	info->vecs = vecs;
	set_dir_vector(info, vecs);
	vecs->pos_x = info->user_x + 0.5;
	vecs->pos_y = info->user_y + 0.5;
	vecs->plane_x = (vecs->dir_y * -1) * 0.66;
	vecs->plane_y = (vecs->dir_x) * 0.66;
}

void	rotate_vectors(double *old_vec_x, double *old_vec_y, double angle)
{
	double	vec_x;
	double	vec_y;
	double	new_vec_x;
	double	new_vec_y;
	double	radian;

	radian = M_PI / 180.0 * angle;
	vec_x = *old_vec_x;
	vec_y = *old_vec_y;
	new_vec_x = vec_x * cos(radian) - vec_y * sin(radian);
	new_vec_y = vec_x * sin(radian) + vec_y * cos(radian);
	*old_vec_x = new_vec_x;
	*old_vec_y = new_vec_y;
}

void	set_move_vectors(t_vec *vecs, int x)
{
	vecs->camera_x = (2 * x) / WIDTH - 1;
	vecs->raydir_x = vecs->dir_x + vecs->camera_x * vecs->plane_x;
	vecs->raydir_y = vecs->dir_y + vecs->camera_x * vecs->plane_y;
}
