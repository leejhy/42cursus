/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inghwang <inghwang@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:02:33 by inghwang          #+#    #+#             */
/*   Updated: 2023/10/12 12:02:37 by inghwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_sign(char *str, int *sign)
{
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		str++;
		*sign *= -1;
	}
	else if (*str == '+')
		str++;
	return (str);
}

int	ft_number(char *str, int sign)
{
	int	answer;

	answer = 0;
	while (*str >= '0' && *str <= '9')
	{
		answer *= 10;
		answer += *str - 48;
		str++;
	}
	return (answer * sign);
}

int	ft_atoi(const char *str)
{
	int	sign;

	sign = 1;
	str = ft_sign((char *)str, &sign);
	return (ft_number((char *)str, sign));
}
