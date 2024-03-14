/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:22:41 by inghwang          #+#    #+#             */
/*   Updated: 2024/03/14 20:36:38 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	finish(t_tool *tool)
{
	mlx_destroy_window(tool->mlx_ptr, tool->win_ptr);
	tool_free(tool);
	exit(0);
	return (0);
}

static int	move_possible_utils(t_tool *tool, int row, int col)
{
	int	row_re;
	int	col_re;

	row_re = row % LEN;
	col_re = col % LEN;
	if ((tool->map)[row / LEN][col / LEN] == '1')
		return (0);
	if (row_re > 0)
	{
		if (tool->map[row / LEN + 1][col / LEN] == '1')
			return (0);
	}
	if (col_re > 0)
	{
		if (tool->map[row / LEN][col / LEN + 1] == '1')
			return (0);
		else if (row_re > 0 && tool->map[row / LEN + 1][col / LEN + 1] == '1')
			return (0);
	}
	return (1);
}

static void	move_possible(t_tool *tool, int row, int col, int keycode)
{
	if (keycode == 1) //s
	{
		if (move_possible_utils(tool, row + 8, col))
			tool->usr_row += 8;
	}
	else if (keycode == 13) //w
	{
		if (move_possible_utils(tool, row - 8, col))
			tool->usr_row -= 8;
	}
	else if (keycode == 0) //a
	{
		if (move_possible_utils(tool, row, col - 8))
			tool->usr_col -= 8;
	}
	else if (keycode == 2) //d
	{
		if (move_possible_utils(tool, row, col + 8))
			tool->usr_col += 8;
	}
}

int	key_press(int keycode, t_tool *tool)
{
	if (keycode == 53)  //esc
		finish(tool);
	move_possible(tool, tool->usr_row, tool->usr_col, keycode);
	img_print(tool);
	return (1);
}
