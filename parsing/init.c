/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:38:58 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/25 21:57:41 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	coord_init(t_coord *coord)
{
	coord->width = 1280;//윈도우 중앙x
	coord->height = 800;//윈도우 중앙y
	coord->gap = 25;
	coord->z_gap = 5;
	// coord->offset_x = (coord->width / 2) - coord->gap * (coord->col / 2);//offset 수정
	// coord->offset_y = (coord->height / 2) - coord->gap * (coord->row / 2);
}

t_xyz	**xyz_malloc(int row, int col)
{
	t_xyz	**temp_xyz;
	int	i;

	i = 0;
	temp_xyz = malloc(sizeof(t_xyz *) * (row + 1));//row만큼 malloc t_xyz *malloc하기
	if (temp_xyz == NULL)
		malloc_failed();
	while (i < row)
	{
		temp_xyz[i] = malloc(sizeof(t_xyz) * col);
		i++;
	}
	temp_xyz[i] = NULL;
	return (temp_xyz);
}

void	xyz_map_init(t_coord *coord, int **z_map)
{
	int	i;
	int	j;

	i = 0;
	coord->xyz_map = xyz_malloc(coord->row, coord->col);
	while (coord->gap != 5 && coord->gap * (coord->col - 1) > coord->width)//최대 좌표가 최소 5까지 줄이기
		coord->gap -= 1;
	coord->z_gap = coord->gap / 5;//
	while (coord->xyz_map[i])
	{
		j = 0;
		while (j < coord->col)
		{
			coord->xyz_map[i][j].x = coord->gap * j;
			coord->xyz_map[i][j].y = coord->gap * i;
			coord->xyz_map[i][j].z = coord->z_gap * z_map[i][j];
			j++;
		}
		i++;
	}
}

void	rotate_init(t_coord *coord)
{
	int		i;
	int		j;
	t_xyz	**xyz;

	i = 0;
	xyz = coord->xyz_map;
	while (xyz[i])
	{
		j = 0;
		while (j < coord->col)
		{
			euler_z(&xyz[i][j].x, &xyz[i][j].y, 45.0);
			euler_x(&xyz[i][j].y, &xyz[i][j].z, 35.264);
			j++;
		}
		i++;
	}
	coord->offset_x = coord->width / 2 - xyz[i / 2][j / 2].x;//offset_수정
	coord->offset_y = coord->height / 2 - xyz[i / 2][j / 2].y;
}
