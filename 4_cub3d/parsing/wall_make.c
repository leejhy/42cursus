/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_make.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:29:24 by inghwang          #+#    #+#             */
/*   Updated: 2024/03/26 13:28:15 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	init(t_wall *wall, t_info *info)
{
	wall->data = 0;
	wall->str = 0;
	wall->north = 0;
	wall->south = 0;
	wall->west = 0;
	wall->east = 0;
	info->map = 0;
	info->floor = 0;
	info->ceiling = 0;
	info->row = 0;
	info->col = 0;
	info->direction = 0;
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

static void	data_make(t_wall *wall, int fd)
{
	char	*buffer;

	while (1)
	{
		buffer = get_next_line(fd);
		if (buffer == 0)
			break ;
		wall->str = ft_strjoin_free(wall->str, buffer);
		if (wall->str == 0)
		{
			close(fd);
			error(wall->str, 0);
		}
		free(buffer);
	}
	close(fd);
	error(wall->str, "wrong data");
	wall->data = ft_split(wall->str, '\n');
	error(wall->data, 0);
}

void	wall_make(t_wall *wall, t_info *info, int argc, char *argv[])
{
	if (argc != 2)
		error(0, "wrong arg");
	init(wall, info);
	data_make(wall, make_fd(argv[1]));
}
