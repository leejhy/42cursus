/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:58:56 by junhylee          #+#    #+#             */
/*   Updated: 2023/11/07 20:50:50 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// int	is_lf(int read_len, char *buf)
// {
// 	int	i;

// 	i = 0;
// 	while (i < read_len)
// 	{
// 		if (buf[i] == '\n')
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

char	*get_next_line(int fd)
{
	size_t		read_size;
	size_t		read_return;
	size_t		i;
	static char	*ptr;
	char		*str;
	int			flag;

	flag = 0;
	read_size = 0;
	read_return = 1;
	if (fd < 0)
		return (NULL);
	ptr = malloc(sizeof(char) * (2 + 1));
	read_return = read(fd, ptr, 2);
	str = ft_strdup(ptr);
	while (flag == 0)
	{
		i = 0;
		read_return = read(fd, ptr, 2);
		if (read_return == 0)
			break ;
		while (i < read_return)//read_return 만큼만 읽어야지 쓰레기값 안받음
		{
			// printf("%d ", ptr[i]);
			if (ptr[i] == '\n')
			{
				ptr[i + 1] = '\0';
				flag = 1;
				break ;
			}
			i++;
		}
		str = ft_strjoin(str, ptr);
	}
	free(ptr);
	return (str);
}

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("text.txt", O_RDONLY);
	//open해서 text.txt의? fd 저장
	str = get_next_line(fd);
	printf("%s", str);
}
