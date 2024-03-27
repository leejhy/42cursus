/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:20:29 by inghwang          #+#    #+#             */
/*   Updated: 2024/03/26 13:26:11 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	space_check(char c)
{
	if (c == 32)
		return (1);
	else if (c >= 9 && c <= 13)
		return (1);
	return (0);
}

static char	*str_free(void *str)
{
	if (str != 0)
		free(str);
	return (0);
}

void	wall_free(t_wall *wall)
{
	int	i;

	if (wall != 0)
	{
		wall->str = str_free(wall->str);
		wall->north = str_free(wall->north);
		wall->south = str_free(wall->south);
		wall->west = str_free(wall->west);
		wall->east = str_free(wall->east);
		if (wall->data != 0)
		{
			i = -1;
			while ((wall->data)[++i] != 0)
			{
				free((wall->data)[i]);
				(wall->data)[i] = 0;
			}
			free(wall->data);
			wall->data = 0;
		}
	}
}

void	info_free(t_info *info)
{
	int	i;

	if (info != 0)
	{
		if (info->map != 0)
		{
			i = -1;
			while ((info->map)[++i] != 0)
			{
				free((info->map)[i]);
				(info->map)[i] = 0;
			}
			free(info->map);
			info->map = 0;
		}
		info->north = str_free(info->north);
		info->south = str_free(info->south);
		info->west = str_free(info->west);
		info->east = str_free(info->east);
		info->floor = str_free(info->floor);
		info->ceiling = str_free(info->ceiling);
	}
}

void	error(void *str, char *message)
{
	if (str == 0)
	{
		ft_putendl_fd("Error", 2);
		if (message == 0)
			perror("");
		else
			ft_putendl_fd(message, 2);
		exit(1);
	}
}
