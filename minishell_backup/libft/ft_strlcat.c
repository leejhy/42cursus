/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:31:13 by tajeong           #+#    #+#             */
/*   Updated: 2023/10/07 16:33:20 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dsize;
	size_t	iter;

	dsize = ft_strlen(dst);
	iter = 0;
	while (dsize + iter + 1 < dstsize && src[iter])
	{
		dst[dsize + iter] = src[iter];
		iter++;
	}
	dst[dsize + iter] = 0;
	if (dstsize > dsize)
		dstsize = dsize;
	return (ft_strlen(src) + dstsize);
}
