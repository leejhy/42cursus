/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 22:31:23 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/25 18:23:40 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_coord	coord;
	int		**z_map;

	if (argc != 2)
		args_error();
	z_map = parsing(argv[1], &coord.col, &coord.row); //free 해줘야함
	coord_init(&coord);
	xyz_map_init(&coord, z_map);
	rotate_init(&coord);// 얘가 문제
}
