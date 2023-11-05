/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:36:38 by junhylee          #+#    #+#             */
/*   Updated: 2023/10/15 19:53:42 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	length_src;

	i = 0;
	length_src = ft_strlen(src);
	if (dstsize == 0)
		return (length_src);
	while ((i + 1 < dstsize) && *(src + i))
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = '\0';
	return (length_src);
}
