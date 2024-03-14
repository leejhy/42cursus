/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inghwang <inghwang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:20:29 by inghwang          #+#    #+#             */
/*   Updated: 2024/03/02 18:20:52 by inghwang         ###   ########.fr       */
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

void	infor_free(t_infor *infor)
{
	int	i;

	if (infor != 0)
	{
		infor->str = str_free(infor->str);
		infor->north = str_free(infor->north);
		infor->south = str_free(infor->south);
		infor->west = str_free(infor->west);
		infor->east = str_free(infor->east);
		if (infor->data != 0)
		{
			i = -1;
			while ((infor->data)[++i] != 0)
			{
				free((infor->data)[i]);
				(infor->data)[i] = 0;
			}
			free(infor->data);
			infor->data = 0;
		}
	}
}

void	tool_free(t_tool *tool)
{
	int	i;

	if (tool != 0)
	{
		if (tool->map != 0)
		{
			i = -1;
			while ((tool->map)[++i] != 0)
			{
				free((tool->map)[i]);
				(tool->map)[i] = 0;
			}
			free(tool->map);
			tool->map = 0;
		}
		//leaks
		//tool->north = str_free(tool->north);
		//tool->south = str_free(tool->south);
		//tool->west = str_free(tool->west);
		//tool->east = str_free(tool->east);
		tool->floor = str_free(tool->floor);
		tool->ceiling = str_free(tool->ceiling);
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
