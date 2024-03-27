/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inghwang <inghwang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 09:28:29 by inghwang          #+#    #+#             */
/*   Updated: 2023/10/12 16:17:44 by inghwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t destsize)
{
	size_t	i;
	size_t	src_i;

	src_i = 0;
	while (*(src + src_i))
	{
		src_i++;
	}
	if (!dst || !src)
		return (0);
	i = 0;
	while (*(src + i) && i + 1 < destsize)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	if (destsize > 0)
		*(dst + i) = '\0';
	return (src_i);
}
