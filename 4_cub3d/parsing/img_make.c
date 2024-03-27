/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_make.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:18:10 by inghwang          #+#    #+#             */
/*   Updated: 2024/03/26 14:38:38 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	**img_make_util(int *loc)
{
	int	**result;
	int	y;
	int	x;

	result = malloc(sizeof(int *) * TEXTURE_HEIGHT);
	if (!result)
		exit(1);
	y = -1;
	while (++y < 64)
	{
		result[y] = malloc(sizeof(int) * 64);
		if (!result[y])
			exit(1);
		x = -1;
		while (++x < 64)
			result[y][x] = loc[64 * y + x];
	}
	return (result);
}

void	img_make(t_info *info, t_wall *wall, t_data *img, t_vars *vars)
{
	int	len[3];

	info->north = mlx_xpm_file_to_image(vars->mlx, \
			wall->north, &len[0], &len[1]);
	info->south = mlx_xpm_file_to_image(vars->mlx, \
			wall->south, &len[0], &len[1]);
	info->west = mlx_xpm_file_to_image(vars->mlx, \
			wall->west, &len[0], &len[1]);
	info->east = mlx_xpm_file_to_image(vars->mlx, \
			wall->east, &len[0], &len[1]);
	if (info->north == 0 || info->south == 0 || \
	info->west == 0 || info->east == 0)
		error(0, "map img error");
	wall->north_addr = (int *)mlx_get_data_addr(info->north, &len[0], \
	&len[1], &len[2]);
	wall->south_addr = (int *)mlx_get_data_addr(info->south, &len[0], \
	&len[1], &len[2]);
	wall->west_addr = (int *)mlx_get_data_addr(info->west, &len[0], \
	&len[1], &len[2]);
	wall->east_addr = (int *)mlx_get_data_addr(info->east, &len[0], \
	&len[1], &len[2]);
	img->wall_north = img_make_util(wall->north_addr);
	img->wall_south = img_make_util(wall->south_addr);
	img->wall_west = img_make_util(wall->west_addr);
	img->wall_east = img_make_util(wall->east_addr);
}
