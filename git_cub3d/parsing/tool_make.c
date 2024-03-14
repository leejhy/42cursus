/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_inspect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inghwang <inghwang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:17:40 by inghwang          #+#    #+#             */
/*   Updated: 2024/02/29 16:26:44 by inghwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	img_check(t_infor *infor, t_tool *tool)
{
	if (tool->floor != 0 && \
	tool->ceiling != 0 && \
	infor->east != 0 && \
	infor->west != 0 && \
	infor->south != 0 && \
	infor->north != 0)
	{
		if (!ft_strncmp(infor->north, infor->south, ft_strlen(infor->north) + 1))
			error(0, "data error");
		if (!ft_strncmp(infor->north, infor->west, ft_strlen(infor->north) + 1))
			error(0, "data error");
		if (!ft_strncmp(infor->north, infor->east, ft_strlen(infor->north) + 1))
			error(0, "data error");
		if (!ft_strncmp(infor->south, infor->west, ft_strlen(infor->south) + 1))
			error(0, "data error");
		if (!ft_strncmp(infor->south, infor->east, ft_strlen(infor->south) + 1))
			error(0, "data error");
		if (!ft_strncmp(infor->west, infor->east, ft_strlen(infor->west) + 1))
			error(0, "data error");
		return (1);
	}
	return (0);
}

static int	map_start_utils(char **map, int *flag)
{
	int	len;

	len = 0;
	if (map[(*flag)++] == 0)
		error(0, "wrong data");
	while (map[(*flag)] != 0 && map[(*flag)][0] == '\n')
		(*flag)++;
	while (map[(*flag) + len] != 0)
		len++;
	while (len > 0 && map[(*flag) + len - 1][0] == '\n')
	{
		len--;
	}
	return (len);
}

static void	map_start(t_infor *infor, t_tool *tool, int flag)
{
	int	i;
	int	len;

	len = map_start_utils(infor->data, &flag);
	if (len < 3)
		error(0, "wrong data");
	tool->map = malloc(sizeof(char *) * (len + 1));
	error(tool->map, 0);
	i = -1;
	while (++i < len)
	{
		(tool->map)[i] = ft_calloc(sizeof(char), \
		ft_strlen((infor->data)[flag + i]) + 1);
		error((tool->map)[i], 0);
		ft_strlcat((tool->map)[i], (infor->data)[flag + i], \
		ft_strlen((infor->data)[flag + i]) + 1);
	}
	(tool->map)[i] = 0;
}

static char	*tool_make_utils(char *str, int len)
{
	char	*answer;

	if (len == 0)
	{
		if (str[0] == '\n')
			return (0);
		error(0, "wrong data");
	}
	while (space_check(str[len]))
		len++;
	answer = ft_substr(str, len, ft_strlen(str));
	error(answer, 0);
	// if (answer == 0)
	// 	error(0, 0);
	return (answer);
}

void	tool_make(t_infor *infor, t_tool *tool)
{
	int	i;

	i = -1;
	while ((infor->data)[++i] != 0)
	{
		if (infor->north == 0 && ft_strnstr((infor->data)[i], "NO ", 3)) //tab은??
			infor->north = tool_make_utils((infor->data)[i], 3);
		else if (infor->south == 0 && ft_strnstr((infor->data)[i], "SO ", 3))
			infor->south = tool_make_utils((infor->data)[i], 3);
		else if (infor->west == 0 && ft_strnstr((infor->data)[i], "WE ", 3))
			infor->west = tool_make_utils((infor->data)[i], 3);
		else if (infor->east == 0 && ft_strnstr((infor->data)[i], "EA ", 3))
			infor->east = tool_make_utils((infor->data)[i], 3);
		else if (tool->floor == 0 && (ft_strnstr((infor->data)[i], "F ", 2)))
			tool->floor = tool_make_utils((infor->data)[i], 2);
		else if (tool->ceiling == 0 && ft_strnstr((infor->data)[i], "C ", 2))
			tool->ceiling = tool_make_utils((infor->data)[i], 2);
		else
			tool_make_utils((infor->data)[i], 0);
		if (img_check(infor, tool))
			break ;
	}
	map_start(infor, tool, i);
}
