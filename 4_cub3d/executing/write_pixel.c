/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:29:57 by junhylee          #+#    #+#             */
/*   Updated: 2024/03/26 15:41:07 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_rgb	*make_rgb(char *str)
{
	t_rgb	*rgb;

	rgb = malloc(sizeof(t_rgb));
	rgb->r = ft_atoi(str);
	while (*str && ('0' <= *str && *str <= '9'))
		str++;
	if (*str != '\0')
		str++;
	rgb->g = ft_atoi(str);
	while (*str && ('0' <= *str && *str <= '9'))
		str++;
	if (*str != '\0')
		str++;
	rgb->b = ft_atoi(str);
	while (*str && ('0' <= *str && *str <= '9'))
		str++;
	if (*str != '\0')
	{
		ft_putendl_fd("color error", 2);
		exit(1);
	}
	return (rgb);
}

void	write_sky_ground(int x, t_info *info)
{
	int		sky;
	int		ground;
	t_rgb	*f_rgb;
	t_rgb	*c_rgb;

	sky = 0;
	ground = HEIGHT / 2;
	f_rgb = info->floor_rgb;
	c_rgb = info->ceiling_rgb;
	while (sky < HEIGHT / 2)
	{
		my_mlx_pixel_put(info->pixel_img, x, sky, \
						create_trgb(0, c_rgb->r, c_rgb->g, c_rgb->b));
		sky++;
	}
	while (ground < HEIGHT)
	{
		my_mlx_pixel_put(info->pixel_img, x, ground, \
						create_trgb(0, f_rgb->r, f_rgb->g, f_rgb->b));
		ground++;
	}
}
