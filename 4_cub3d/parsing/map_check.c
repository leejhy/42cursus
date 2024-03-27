/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 09:37:52 by inghwang          #+#    #+#             */
/*   Updated: 2024/03/24 20:27:29 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	element_check(t_info *info, int i, int j, int *flag)
{
	int	z;

	z = -1;
	while ("01NSWE"[++z] != '\0')
	{
		if ((info->map)[i][j] == "01NSWE"[z])
			break ;
	}
	if ("01NSWE"[z] == '\0')
		error(0, "map error");
	if (z > 1 && *flag == 1)
		error(0, "map error");
	if (z > 1)
	{
		info->direction = "01NSWE"[z];
		info->user_y = i;
		info->user_x = j;
		*flag = 1;
	}
}

static void	map_space(char **map, int i, int j)
{
	if (i - 1 >= 0 && ft_strlen(map[i - 1]) > (size_t)j)
	{
		if (!space_check(map[i - 1][j]) && map[i - 1][j] != '1')
			error(0, "map error");
	}
	if (map[i + 1] != 0 && ft_strlen(map[i + 1]) > (size_t)j)
	{
		if (!space_check(map[i + 1][j]) && map[i + 1][j] != '1')
			error(0, "map error");
	}
	if (j - 1 >= 0)
	{
		if (!space_check(map[i][j - 1]) && map[i][j - 1] != '1')
			error(0, "map error");
	}
	if (map[i][j + 1] != '\0')
	{
		if (!space_check(map[i][j + 1]) && map[i][j + 1] != '1')
			error(0, "map error");
	}
}

static void	map_first_last_one(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i] != 0)
	{
		if (map[i][0] != '1' && !space_check(map[i][0]))
			error(0, "map error");
		if (map[i][ft_strlen(map[i]) - 1] != '1' && \
		!space_check(map[i][ft_strlen(map[i]) - 1]))
			error(0, "map error");
	}
	j = -1;
	while (map[0][++j] != 0)
	{
		if (map[0][j] != '1' && !space_check(map[0][j]))
			error(0, "map error");
	}
	j = -1;
	while (map[i - 1][++j] != 0)
	{
		if (map[i - 1][j] != '1' && !space_check(map[i - 1][j]))
			error(0, "map error");
	}
}

static void	map_middle_one(char **map, int row, int p_row, int n_row)
{
	int	i;

	i = -1;
	while (map[++i] != 0)
	{
		if (i > 0)
			p_row = ft_strlen(map[i - 1]);
		n_row = ft_strlen(map[i + 1]);
		row = ft_strlen(map[i]);
		while (i > 0 && row - p_row > 0 && map[i][row - 1])
		{
			if (map[i][row - 1] != '1' && !space_check(map[i][row - 1]))
				error(0, "map error");
			row--;
		}
		row = ft_strlen(map[i]);
		while (map[i + 1] != 0 && row - n_row > 0 && map[i][row - 1])
		{
			if (map[i][row - 1] != '1' && !space_check(map[i][row - 1]))
				error(0, "map error");
			row--;
		}
	}
}

void	map_check(t_info *info)
{
	int	i;
	int	j;
	int	flag;

	i = -1;
	flag = 0;
	while ((info->map)[++i] != 0)
	{
		j = -1;
		while ((info->map)[i][++j] != '\0')
		{
			if (!space_check((info->map)[i][j]))
				element_check(info, i, j, &flag);
			else
				map_space((info->map), i, j);
		}
		if (j > info->col)
			info->col = j;
	}
	info->row = i;
	if (flag == 0)
		error(0, "map error");
	map_first_last_one(info->map);
	map_middle_one(info->map, 0, 0, 0);
}
