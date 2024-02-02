/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 21:06:00 by tajeong           #+#    #+#             */
/*   Updated: 2023/10/08 13:31:43 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				sign;
	unsigned long	res;

	sign = 1;
	res = 0;
	while (ft_strchr("\t\n\v\f\r ", *str) && *str)
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	while (ft_isalnum(*str) && !ft_isalpha(*str) && *str)
	{
		if (res * 10 + (unsigned long)(*str - '0') > \
			(unsigned long)9223372036854775807 || \
			res > (unsigned long)9223372036854775807 / 10)
			return (-1 + (sign == -1));
		res *= 10;
		res += (unsigned long)(*str - '0');
		str++;
	}
	return ((int)(sign * res));
}
