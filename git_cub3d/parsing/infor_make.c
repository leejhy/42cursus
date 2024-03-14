/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_inspect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inghwang <inghwang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:29:24 by inghwang          #+#    #+#             */
/*   Updated: 2024/02/27 17:30:06 by inghwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	init(t_infor *infor, t_tool *tool)
{
	infor->data = 0;
	infor->str = 0;
	infor->north = 0;
	infor->south = 0;
	infor->west = 0;
	infor->east = 0;
	tool->map = 0;
	tool->floor = 0;
	tool->ceiling = 0;
	tool->row = 0;
	tool->col = 0;
}

static int	make_fd(char *str)
{
	int		fd;
	char	*path;

	if (ft_strnstr_rev(str, ".cub", 4) == 0)
		error(0, "wrong arg");
	if (ft_strchr(str, '/'))
	{
		fd = open(str, O_RDONLY);
		if (fd < 0)
			error(0, 0);
	}
	else
	{
		path = ft_strjoin("./", str);
		error(path, 0);
		fd = open(path, O_RDONLY);
		free(path);
		if (fd < 0)
			error(0, 0);
	}
	return (fd);
}

static void	data_make(t_infor *infor, int fd)
{
	char	*buffer;

	while (1)
	{
		buffer = get_next_line(fd);
		if (buffer == 0)
			break ;
		infor->str = ft_strjoin_free(infor->str, buffer);
		if (infor->str == 0)
		{
			close(fd);
			error(infor->str, 0);
		}
		free(buffer);
	}
	close(fd);
	error(infor->str, "data error");
	infor->data = ft_split(infor->str, '\n');
	error(infor->data, 0);
}

void	infor_make(t_infor *infor, t_tool *tool, int argc, char *argv[])
{
	if (argc != 2)
		error(0, "wrong arg");
	init(infor, tool);
	data_make(infor, make_fd(argv[1]));
}
