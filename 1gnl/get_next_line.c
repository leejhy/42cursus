/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:58:56 by junhylee          #+#    #+#             */
/*   Updated: 2023/11/13 20:25:19 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buf;
	char		*temp;
	static char	*str;
	static int	read_idx;
	size_t		read_size;
	int			flag;

	flag = 0;
	str = NULL;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (fd >= 0 && flag == 0)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size == 0)
			break ;
		while (read_size <= BUFFER_SIZE)
			buf[read_size++] = '\0';
		read_size = ft_withlf(buf, &flag);
		str = get_str(str, buf, read_size);
		if (!str)
			break ;
		if (read_size < BUFFER_SIZE)
			break ;
	}
	free(buf);
	temp = ft_substr(str, buf, read_size);
	return (str);
}
