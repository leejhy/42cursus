/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:15:03 by inghwang          #+#    #+#             */
/*   Updated: 2024/03/26 16:15:00 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	frees(t_info *info)
{
	int	i;

	i = 0;
	free(info->vecs);
	while (i < TEXTURE_WIDTH)
	{
		free(info->pixel_img->wall_east[i]);
		free(info->pixel_img->wall_west[i]);
		free(info->pixel_img->wall_north[i]);
		free(info->pixel_img->wall_south[i]);
		i++;
	}
	free(info->pixel_img->wall_east);
	free(info->pixel_img->wall_west);
	free(info->pixel_img->wall_north);
	free(info->pixel_img->wall_south);
	free(info->floor_rgb);
	free(info->ceiling_rgb);
	wall_free(info->wall);
	info_free(info);
}

int	main(int argc, char *argv[])
{
	t_wall	wall;
	t_info	info;
	t_vars	vars;
	t_data	pixel_img;

	info.wall = &wall;
	wall_make(&wall, &info, argc, argv);
	info_make(&wall, &info);
	map_check(&info);
	vars_img_init(&vars, &pixel_img);
	img_make(&info, &wall, &pixel_img, &vars);
	info.vars = &vars;
	info.pixel_img = &pixel_img;
	set_vectors(&info);
	info.ceiling_rgb = make_rgb(info.ceiling);
	info.floor_rgb = make_rgb(info.floor);
	run_raycasting(&info, info.vecs);
	mlx_put_image_to_window(vars.mlx, vars.win, pixel_img.img, 0, 0);
	mlx_hook(vars.win, 2, 0, key_press, &info);
	mlx_hook(vars.win, 17, 0, exit_hook, &info);
	mlx_loop(vars.mlx);
}
