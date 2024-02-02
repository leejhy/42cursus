/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 01:56:16 by tajeong           #+#    #+#             */
/*   Updated: 2023/10/08 13:38:16 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_digit_size(int n)
{
	size_t	size;

	if (n > 0)
		n *= -1;
	size = 1;
	while (n < 0)
	{
		if (n / 10 != 0)
			size++;
		n /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	size;
	size_t	iter;
	size_t	sign;

	sign = (n < 0);
	iter = 0;
	size = ft_get_digit_size(n);
	res = (char *)ft_calloc(sign + size + 1, sizeof(char));
	if (!res)
		return (0);
	res[0] = '-';
	if (n > 0)
		n *= -1;
	while (iter < size)
	{
		res[sign + size - 1 - iter] = (char)(-(n % 10) + '0');
		n /= 10;
		iter++;
	}
	return (res);
}
