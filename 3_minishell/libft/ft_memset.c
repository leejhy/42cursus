/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:35:49 by tajeong           #+#    #+#             */
/*   Updated: 2023/10/07 16:35:57 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			iter;
	unsigned char	uc;
	unsigned char	*dst;

	iter = 0;
	dst = (unsigned char *)b;
	uc = (unsigned char)c;
	while (iter < len)
	{
		dst[iter] = uc;
		iter++;
	}
	return (b);
}
