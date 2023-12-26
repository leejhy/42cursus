/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:20:02 by junhylee          #+#    #+#             */
/*   Updated: 2023/12/23 13:57:30 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoi(const char *str)
{//수정
	int			sign;
	long long	result;

	sign = 1;
	result = 0;
	// while ((9 <= *str && *str <= 13) || *str == ' ')
	// 	str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}

int	*ft_parsing(int argc, char **argv)
{
	long long	nb;
	int			*nb_arr;
	int			i;

	i = 0;
	nb_arr = malloc(sizeof(int) * (argc - 1));
	if (!nb_arr)
		return (NULL);
	while (i < argc - 1)
	{
		nb = ft_atoi(argv[i + 1]);
		if (nb < INT_MIN || INT_MAX < nb)
		{
			free(nb_arr);
			return (NULL);
		}
		nb_arr[i] = nb;
		i++;
	}
	return (nb_arr);
	//if (argc == 2)
}
