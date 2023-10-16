/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:17:38 by junhylee          #+#    #+#             */
/*   Updated: 2023/10/16 19:04:43 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*temp_src;
	unsigned char	*temp_dst;

	i = 0;
	temp_dst = (unsigned char *)dst;
	temp_src = (unsigned char *)src;
	if (temp_dst == NULL && temp_src == NULL)
		return (NULL);
	if (temp_dst <= temp_src)
		return (ft_memcpy(temp_dst, temp_src, len));
	else
	{
		while (i < len)
		{
			*(temp_dst + (len - 1 - i)) = *(temp_src + (len - 1 - i));
			i++;
		}
	}
	return (dst);
}
