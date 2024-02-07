/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:49:44 by tajeong           #+#    #+#             */
/*   Updated: 2023/10/13 16:12:24 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*chardst;
	unsigned char	*charsrc;
	size_t			iter;

	chardst = (unsigned char *)dst;
	charsrc = (unsigned char *)src;
	if (chardst < charsrc)
	{
		iter = 0;
		while (iter < len)
		{
			chardst[iter] = charsrc[iter];
			iter++;
		}
	}
	else if (charsrc < chardst && len > 0)
	{
		iter = 0;
		while (iter < len)
		{
			chardst[len - 1 - iter] = charsrc[len - 1 - iter];
			iter++;
		}
	}
	return (dst);
}
