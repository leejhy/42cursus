/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:21:24 by inghwang          #+#    #+#             */
/*   Updated: 2024/03/14 20:46:01 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include "./gnl/get_next_line.h"

# define LEN 64

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;


typedef struct s_infor
{
	char	**data;
	char	*str;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
}	t_infor;

typedef struct s_tool
{
	char	**map;
	t_data	*data;
	void	*mlx_ptr;
	void	*win_ptr;//img ptr
	void	*north;
	void	*south;
	void	*west;
	void	*east;
	char	*floor;
	char	*ceiling;
	int		row;
	int		col;
	int		usr_row;
	int		usr_col;
	int		dda_row;
	int		dda_col;
}	t_tool;

void	error(void *str, char *message);
void	infor_make(t_infor *infor, t_tool *tool, int argc, char *argv[]);
int		space_check(char c);
void	infor_free(t_infor *infor);
void	tool_make(t_infor *infor, t_tool *tool);
void	tool_free(t_tool *tool);
void	map_check(t_tool *tool);
void	path_check(t_tool *tool);
void	img_make(t_tool *tool, t_infor *infor, t_data *img);
void	img_print(t_tool *tool);
int		finish(t_tool *tool);
int		key_press(int keycode, t_tool *tool);
// int		cur_postion_utils(t_tool *tool, char c, int flag);

#endif
