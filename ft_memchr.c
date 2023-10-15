/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:00:41 by junhylee          #+#    #+#             */
/*   Updated: 2023/10/15 18:27:41 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*temp_s;

	temp_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*(temp_s + i) == (unsigned char)c)
			return (temp_s + i);
		i++;
	}
	return (NULL);
}
