/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:03:46 by junhylee          #+#    #+#             */
/*   Updated: 2023/11/05 16:39:27 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (dst == NULL && dstsize == 0)
		return (src_len);
	dest_len = ft_strlen(dst);
	if (dest_len < dstsize)
	{
		while (i < dstsize - dest_len - 1 && *(src + i))
		{
			*(dst + dest_len + i) = *(src + i);
			i++;
		}
		*(dst + dest_len + i) = '\0';
		return (src_len + dest_len);
	}
	else
		return (src_len + dstsize);
}
