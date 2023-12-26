/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:20:02 by junhylee          #+#    #+#             */
/*   Updated: 2023/12/26 19:39:29 by junhylee         ###   ########.fr       */
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

int	isDuplicate(int *arr, int arr_cnt)
{
	int	i;
	int	j;

	i = 0;
	while (i < arr_cnt)
	{
		j = 0;
		while (j < arr_cnt)
		{
			if (i != j && arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
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
	if (isDuplicate(nb_arr, argc - 1))
		return (NULL);
	return (nb_arr);
}
