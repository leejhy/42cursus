/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inghwang <inghwang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:18:46 by inghwang          #+#    #+#             */
/*   Updated: 2023/10/14 17:10:42 by inghwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*k1;
	unsigned char	*k2;

	k1 = (unsigned char *)s1;
	k2 = (unsigned char *)s2;
	while (n)
	{
		if (*k1 != *k2)
			return (*k1 - *k2);
		k1++;
		k2++;
		n--;
	}
	return (0);
}
