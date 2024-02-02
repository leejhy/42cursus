/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:27:51 by tajeong           #+#    #+#             */
/*   Updated: 2023/10/13 16:13:07 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*us1;
	unsigned char	*us2;
	size_t			iter;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	iter = 0;
	while (iter + 1 < n && us1[iter] == us2[iter])
		iter++;
	if (n == 0)
		return (0);
	return (us1[iter] - us2[iter]);
}
