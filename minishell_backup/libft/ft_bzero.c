/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:06:41 by tajeong           #+#    #+#             */
/*   Updated: 2023/10/07 16:47:57 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			iter;
	unsigned char	*us;

	iter = 0;
	us = (unsigned char *)s;
	while (iter < n)
	{
		us[iter] = 0;
		iter++;
	}
}
