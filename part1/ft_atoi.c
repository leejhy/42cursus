/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:56:02 by junhylee          #+#    #+#             */
/*   Updated: 2023/10/15 15:58:30 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"

int	ft_atoi(const char *str)
{
	int			sign;
	long long	result;

	sign = 1;
	result = 0;
	while (*str == ' ')
		str++;
	if (*str == '-')
	{
		str++;
		sign = -1;
	}
	if (*str == '+')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}

#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	printf("%d\n",atoi("2147483647"));
	printf("%d\n",ft_atoi("2147483647"));
	printf("%d\n",atoi("-2147483648"));
	printf("%d\n\n",ft_atoi("-2147483648"));
	printf("%d\n",atoi("2147483648"));//오버플로우
	printf("%d\n",ft_atoi("2147483648"));
	printf("%d\n",atoi("-2147483649"));//언더플로우
	printf("%d\n",ft_atoi("-2147483649"));

}