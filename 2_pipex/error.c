/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:48:31 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/11 18:13:19 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(int err)
{
	char	*str;
	size_t	len;

	len = 0;
	str = strerror(err);
	while (str[len])
		len++;
	write(2, str, len);
	exit(EXIT_FAILURE);
}

void	malloc_failed(void)
{
	perror("malloc failed");
	exit(1);
}
