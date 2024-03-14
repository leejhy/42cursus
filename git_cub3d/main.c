/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:15:03 by inghwang          #+#    #+#             */
/*   Updated: 2024/03/14 21:33:32 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	pixel_img_init(t_tool *tool, t_data *img)
// {
// 	img->img = mlx_new_image(tool->mlx_ptr, LEN, LEN);
// 	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
// 			&img->line_length, &img->endian);
// 	tool->west = mlx_new_image(tool->mlx_ptr, len[0], len[1])		
// }

int	main(int argc, char *argv[])
{
	t_infor	infor;
	t_tool	tool;
	t_data	img;

	//infor과 tool의 초기화 입력 받은 data 전처리
	infor_make(&infor, &tool, argc, argv);
	//tool과 infor에 data 집어 넣기
	tool_make(&infor, &tool);
	//map이 규칙대로 잘 선언이 되어 있는지
	map_check(&tool);
	printf("%d %d\n", tool.col, tool.row);
	for (int i=0; i < 14; i++)
	{
		for (int j=0; j<38;j++)
		{
			printf("%c ", tool.map[i][j]);
		}
		printf("\n");
	}
	//tool.map만 가지고 와서 파싱부 확인하고 구현하기
	//img 만들기
	// img_make(&tool, &infor, &img); 기존 이미지 메이크부분 날리기
	
	// pixel_img_init(&tool, &img);//픽셀이미지 생성
	
	//img 그리기
	img_print(&tool);
	mlx_hook(tool.win_ptr, 2, 0, &key_press, &tool);
	mlx_hook(tool.win_ptr, 17, 0, &finish, &tool);
	mlx_loop(tool.mlx_ptr);


	// test
	int	i;

	i = -1;
	printf("--MAP--\n");
	while ((tool.map)[++i] != 0)
		printf("%s\n", (tool.map)[i]);
	printf("NO: %s\n", infor.north);
	printf("SO: %s\n", infor.south);
	printf("WE: %s\n", infor.west);
	printf("EA: %s\n", infor.east);
	printf("F: %s\n", tool.floor);
	printf("C: %s\n", tool.ceiling);
	// test

	tool_free(&tool);
	exit(0);
}
