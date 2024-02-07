/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:52:01 by tajeong           #+#    #+#             */
/*   Updated: 2023/10/08 15:33:25 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			iter;
	unsigned char	uc;
	unsigned char	*us;

	uc = (unsigned char)c;
	us = (unsigned char *)s;
	iter = 0;
	while (iter < n)
	{
		if (us[iter] == uc)
			return (&(us[iter]));
		iter++;
	}
	return (0);
}
