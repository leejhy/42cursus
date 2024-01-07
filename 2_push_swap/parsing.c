/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:20:02 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/07 21:47:30 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoll(const char *str)
{
	int			sign;
	long long	result;

	sign = 1;
	result = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!('0' <= *str && *str <= '9'))
		ft_error();
	while ('0' <= *str && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (*str == '-' || *str == '+')
		ft_error();
	return (sign * result);
}

void	is_duplicate(int *arr, size_t arr_max)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < arr_max)
	{
		j = 0;
		while (j < arr_max)
		{
			if (i != j && arr[i] == arr[j])
				ft_error();
			j++;
		}
		i++;
	}
	return ;
}

char	*ft_strjoin(char **argv, size_t sep, size_t arg_cnt, size_t len)
{
	char	*rt_str;
	size_t	i;
	size_t	idx;

	i = 1;
	idx = 0;
	rt_str = malloc(sizeof (char) * (sep + len + 1));
	if (!rt_str)
		failed_malloc();
	while (i <= arg_cnt)
	{
		ft_strcat(rt_str, argv[i], &idx);
		i++;
	}
	rt_str[idx] = '\0';
	return (rt_str);
}

int	*str_to_nbarr(char *str, size_t nb_cnt)
{
	int			*nb_arr;
	size_t		i;
	long long	nb;

	i = 0;
	nb_arr = malloc(sizeof(int) * nb_cnt);
	if (!nb_arr)
		failed_malloc();
	while (*str)
	{
		while (*str && *str == ' ')
			str++;
		if (*str != '\0')
		{
			nb = ft_atoll(str);
			if (nb < INT_MIN || INT_MAX < nb)
				ft_error();
			nb_arr[i] = nb;
		}
		while (*str && *str != ' ')
			str++;
		i += 1;
	}
	is_duplicate(nb_arr, nb_cnt);
	return (nb_arr);
}

char	*parsing(int argc, char **argv)
{
	size_t	arg_cnt;
	size_t	arg_len;
	char	*str;

	arg_cnt = argc - 1;
	arg_len = ft_arg_len(argv, arg_cnt);
	str = ft_strjoin(argv, arg_cnt, arg_cnt, arg_len);
	return (str);
}
