/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:02:33 by inghwang          #+#    #+#             */
/*   Updated: 2024/03/26 15:51:40 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_sign(char *str)
{
	if (*str == '+')
		str++;
	if (!('0' <= *str && *str <= '9'))
	{
		ft_putendl_fd("color error", 2);
		exit(1);
	}
	return (str);
}

int	ft_number(char *str, int sign)
{
	int	answer;

	answer = 0;
	while ('0' <= *str && *str <= '9')
	{
		answer *= 10;
		answer += *str - 48;
		if (answer > 255)
		{
			ft_putendl_fd("color range error", 2);
			exit(1);
		}
		str++;
	}
	if (*str != '\0' && *str != ',' )
	{
		ft_putendl_fd("color argument error", 2);
		exit(1);
	}
	return (answer * sign);
}

int	ft_atoi(const char *str)
{
	int	sign;

	sign = 1;
	str = ft_sign((char *)str);
	return (ft_number((char *)str, sign));
}
