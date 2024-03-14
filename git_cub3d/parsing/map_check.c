/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 09:37:52 by inghwang          #+#    #+#             */
/*   Updated: 2024/03/14 21:16:58 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//지도의 요소가 아닌 것은 없는지(01NSWE)
static void	element_check(t_tool *tool, int i, int j, int *flag)
{
	int	z;

	z = -1;
	while ("01NSWE"[++z] != '\0')
	{
		if ((tool->map)[i][j] == "01NSWE"[z])
			break ;
	}
	if ("01NSWE"[z] == '\0')
		error(0, "map error");
	if (z > 1 && *flag == 1)
		error(0, "map error");
	if (z > 1)
	{
		tool->usr_row = i * LEN;
		tool->usr_col = j * LEN;
		*flag = 1;
	}
}

//공백을 기준으로 동서남북은 무조건 '1' 혹은 ' '
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

//순서대로 맨 위와 맨 아래는 무조건 '1' 혹은 공백
//각 문자열 시작은 '1' 혹은 공백
//각 문자열 끝은 '1' 혹은 공백
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

//중간에 삐죽 나온 부분 처리
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
			if (map[i][row - 1] != '1')
				error(0, "map error");
			row--;
		}
		row = ft_strlen(map[i]);
		while (map[i + 1] != 0 && row - n_row > 0 && map[i][row - 1])
		{
			if (map[i][row - 1] != '1')
				error(0, "map error");
			row--;
		}
	}
}

void	map_check(t_tool *tool)
{
	int	i;
	int	j;
	int	flag;

	i = -1;
	flag = 0;
	while ((tool->map)[++i] != 0)
	{
		j = -1;
		while ((tool->map)[i][++j] != '\0')
		{
			if (!space_check((tool->map)[i][j]))
				element_check(tool, i, j, &flag);
			else
				map_space((tool->map), i, j);
		}
		if (j > tool->col)
			tool->col = j;
	}
	tool->row = i;
	if (flag == 0)
		error(0, "map error");
	map_first_last_one(tool->map);
	map_middle_one(tool->map, 0, 0, 0);
}
