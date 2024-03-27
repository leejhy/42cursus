/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inghwang <inghwang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 09:31:49 by inghwang          #+#    #+#             */
/*   Updated: 2024/01/19 08:58:59 by inghwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	record_line(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i] != '\n' && str[i] != '\0')
	{
		i++;
	}
	if (str[i] == '\n')
		return (i);
	return (-1);
}

char	*answer(int flag, char *str, char **remain)
{
	char	*temp;

	*remain = NULL;
	if (flag < 0)
		return (str);
	temp = gnl_substr(str, 0, flag + 1);
	if (temp == 0)
	{
		free(str);
		return (NULL);
	}
	if ((size_t)flag + 1 < gnl_strlen(str))
	{
		*remain = gnl_substr(str, flag + 1, gnl_strlen(str) - flag - 1);
		if (*remain == NULL)
		{
			free(temp);
			temp = NULL;
		}
	}
	free(str);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	int			read_byte;
	static char	*record;

	if (fd < 0)
		return (NULL);
	if (record_line(record) > 0)
		return (answer(record_line(record), record, &record));
	while (1)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte < 0)
			break ;
		if (read_byte == 0)
			return (answer(record_line(record), record, &record));
		buffer[read_byte] = '\0';
		record = gnl_strjoin(record, buffer);
		if (record == 0)
			return (NULL);
		if (record_line(record) >= 0)
			return (answer(record_line(record), record, &record));
	}
	free(record);
	record = NULL;
	return (NULL);
}
