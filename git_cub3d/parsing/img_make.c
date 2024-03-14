/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_make.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:18:10 by inghwang          #+#    #+#             */
/*   Updated: 2024/03/14 21:12:11 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	img_make(t_tool *tool, t_infor *infor, t_data *data)
{
	int	len[2];

	tool->mlx_ptr = mlx_init();
	tool->north = mlx_xpm_file_to_image(tool->mlx_ptr, \
			infor->north, &len[0], &len[1]);
	tool->south = mlx_xpm_file_to_image(tool->mlx_ptr, \
			infor->south, &len[0], &len[1]);
	tool->west = mlx_xpm_file_to_image(tool->mlx_ptr, \
			infor->west, &len[0], &len[1]);
	tool->east = mlx_xpm_file_to_image(tool->mlx_ptr, \
			infor->east, &len[0], &len[1]);



	data->addr =0;
	data->bits_per_pixel=0;
	data->endian=0;
	data->img=0;
	data->line_length=0;
	data->img = mlx_new_image(tool->mlx_ptr, 64, 64);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	// if (tool->north == 0 || tool->south == 0 || \
	// 	tool->east == 0 || tool->west == 0)
	// 	error(0, "img path error");
	infor_free(infor);
	tool->data = data;
	tool->win_ptr = mlx_new_window(tool->mlx_ptr, \
	LEN * tool->col, LEN * tool->row, "cub3D");

}
