/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:12:39 by tajeong           #+#    #+#             */
/*   Updated: 2023/10/08 05:31:43 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	iter;

	iter = 0;
	while (iter + 1 < dstsize && src[iter])
	{
		dst[iter] = src[iter];
		iter++;
	}
	if (dstsize)
		dst[iter] = 0;
	return (ft_strlen(src));
}
