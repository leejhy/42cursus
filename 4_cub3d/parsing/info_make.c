/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_make.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:17:40 by inghwang          #+#    #+#             */
/*   Updated: 2024/03/26 13:14:44 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	img_check(t_wall *wall, t_info *info)
{
	if (info->floor != 0 && \
	info->ceiling != 0 && \
	wall->east != 0 && \
	wall->west != 0 && \
	wall->south != 0 && \
	wall->north != 0)
	{
		if (!ft_strncmp(wall->north, wall->south, ft_strlen(wall->north) + 1))
			error(0, "data error");
		if (!ft_strncmp(wall->north, wall->west, ft_strlen(wall->north) + 1))
			error(0, "data error");
		if (!ft_strncmp(wall->north, wall->east, ft_strlen(wall->north) + 1))
			error(0, "data error");
		if (!ft_strncmp(wall->south, wall->west, ft_strlen(wall->south) + 1))
			error(0, "data error");
		if (!ft_strncmp(wall->south, wall->east, ft_strlen(wall->south) + 1))
			error(0, "data error");
		if (!ft_strncmp(wall->west, wall->east, ft_strlen(wall->west) + 1))
			error(0, "data error");
		return (1);
	}
	return (0);
}

static int	map_start_utils(char **map, int *flag)
{
	int	len;
	int	enter;

	len = 0;
	if (map[(*flag)++] == 0)
		error(0, "wrong data");
	while (map[(*flag)] != 0 && map[(*flag)][0] == '\n')
		(*flag)++;
	while (map[(*flag) + len] != 0 && map[(*flag) + len][0] != '\n')
		len++;
	enter = 0;
	while (map[(*flag) + len + enter] != 0 && \
	map[(*flag) + len + enter][0] == '\n')
		enter++;
	if (map[(*flag) + len + enter] != 0)
		error(0, "wrong data");
	return (len);
}

static void	map_start(t_wall *wall, t_info *tool, int flag)
{
	int	i;
	int	len;

	len = map_start_utils(wall->data, &flag);
	if (len < 3)
		error(0, "wrong data");
	tool->map = malloc(sizeof(char *) * (len + 1));
	error(tool->map, 0);
	i = -1;
	while (++i < len)
	{
		(tool->map)[i] = ft_calloc(sizeof(char), \
		ft_strlen((wall->data)[flag + i]) + 1);
		error((tool->map)[i], 0);
		ft_strlcat((tool->map)[i], (wall->data)[flag + i], \
		ft_strlen((wall->data)[flag + i]) + 1);
	}
	(tool->map)[i] = 0;
}

static char	*tool_make_utils(char *str, int len)
{
	char	*answer;

	if (len == -1)
	{
		if (str[0] == '\n')
			return (0);
		error(0, "wrong data");
	}
	while (space_check(str[len]))
		len++;
	if (len == 0)
		error(0, "data error");
	if (str[len] == '\0')
		error(0, "data error");
	answer = ft_substr(str, len, ft_strlen(str));
	error(answer, 0);
	return (answer);
}

void	info_make(t_wall *wall, t_info *info)
{
	int	i;

	i = -1;
	while ((wall->data)[++i] != 0)
	{
		if (wall->north == 0 && ft_strnstr((wall->data)[i], "NO", 2))
			wall->north = tool_make_utils((wall->data)[i] + 2, 0);
		else if (wall->south == 0 && ft_strnstr((wall->data)[i], "SO", 2))
			wall->south = tool_make_utils((wall->data)[i] + 2, 0);
		else if (wall->west == 0 && ft_strnstr((wall->data)[i], "WE", 2))
			wall->west = tool_make_utils((wall->data)[i] + 2, 0);
		else if (wall->east == 0 && ft_strnstr((wall->data)[i], "EA", 2))
			wall->east = tool_make_utils((wall->data)[i] + 2, 0);
		else if (info->floor == 0 && (ft_strnstr((wall->data)[i], "F", 1)))
			info->floor = tool_make_utils((wall->data)[i] + 1, 0);
		else if (info->ceiling == 0 && ft_strnstr((wall->data)[i], "C", 1))
			info->ceiling = tool_make_utils((wall->data)[i] + 1, 0);
		else
			tool_make_utils((wall->data)[i], -1);
		if (img_check(wall, info))
			break ;
	}
	map_start(wall, info, i);
}
