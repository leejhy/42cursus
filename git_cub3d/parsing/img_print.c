/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:37:41 by inghwang          #+#    #+#             */
/*   Updated: 2024/03/14 21:12:43 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	img_print_utils(t_tool *tool, int i)
{
	int	j;
	int	len;

	len = ft_strlen((tool->map)[i]);
	j = -1;
	while (++j < len)
	{
		if ((tool->map)[i][j] == '1')
			mlx_put_image_to_window(tool->mlx_ptr, tool->win_ptr, \
			tool->north, LEN * j, LEN * i);
		else if ((tool->map)[i][j] != ' ')
			mlx_put_image_to_window(tool->mlx_ptr, tool->win_ptr, \
			tool->south, LEN * j, LEN * i);
	}
}
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	img_print(t_tool *tool)
{
	int		i;

	i = -1;
	while (++i < tool->row)
		img_print_utils(tool, i);
	//ㅇㅕ기다가 이미지 그리기
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			my_mlx_pixel_put(tool->data, 32 + i, 32 + j, create_trgb(0, 255, 255, 255));
	}
	mlx_put_image_to_window(tool->mlx_ptr, tool->win_ptr, \
			tool->data->img, tool->usr_col, tool->usr_row);
	// mlx_put_image_to_window(tool->mlx_ptr, tool->win_ptr, \
	// 		data->img, tool->usr_col, tool->usr_row);
	// mlx_put_image_to_window(tool->mlx_ptr, tool->win_ptr, img->img, tool->col, tool->row);//펑
}
