/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:39:03 by tajeong           #+#    #+#             */
/*   Updated: 2023/10/13 16:12:42 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*chardst;
	unsigned char	*charsrc;
	size_t			iter;

	chardst = (unsigned char *)dst;
	charsrc = (unsigned char *)src;
	iter = 0;
	while (iter < n && (chardst || charsrc))
	{
		chardst[iter] = charsrc[iter];
		iter++;
	}
	return (dst);
}
