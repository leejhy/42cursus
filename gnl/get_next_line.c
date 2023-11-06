/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:58:56 by junhylee          #+#    #+#             */
/*   Updated: 2023/11/06 21:53:10 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		read_size;
	char	*ptr;
	char	*str;

	if (fd < 0)
		return (NULL);
	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	ptr = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	read_size = read(fd, ptr, BUFFER_SIZE);
	str = ft_strdup(ptr);
	read_size = read(fd, ptr, BUFFER_SIZE);
	str = ft_strdup(ptr);
	printf("%s\n",str);
	printf("%s\n",ptr);
	printf("%d\n",read_size);
	return (str);
}

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("text.txt", O_RDONLY);
	//open해서 text.txt의? fd 저장
	str = get_next_line(fd);
	printf("%s\n", str);
}
