/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inghwang <inghwang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 09:23:15 by inghwang          #+#    #+#             */
/*   Updated: 2023/10/16 09:05:55 by inghwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*temp[2];
	size_t			i;

	temp[0] = (unsigned char *)dst;
	temp[1] = (unsigned char *)src;
	if (temp[0] == NULL && temp[1] == NULL)
		return (NULL);
	if (temp[0] > temp[1])
	{
		while (len > 0)
		{
			len--;
			temp[0][len] = temp[1][len];
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			temp[0][i] = temp[1][i];
			i++;
		}
	}
	return (dst);
}
