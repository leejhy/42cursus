/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:22:41 by inghwang          #+#    #+#             */
/*   Updated: 2024/03/26 16:12:42 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	exit_hook(t_info *info)
{
	mlx_destroy_window(info->vars->mlx, info->vars->win);
	frees(info);
	exit(0);
	return (0);
}

void	vars_img_init(t_vars *vars, t_data *img)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "cub3D");
	img->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < WIDTH && y < HEIGHT)
	{
		dst = data->addr + \
			(y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

int	key_press(int key_code, t_info *info)
{
	if (key_code == 53)
		exit_hook(info);
	if (!(key_code == 0 || key_code == 1
			|| key_code == 2 || key_code == 13
			|| key_code == 123 || key_code == 124))
		return (0);
	control_move(info, key_code);
	return (1);
}
