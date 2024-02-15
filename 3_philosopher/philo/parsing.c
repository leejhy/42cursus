/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:25:25 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/15 18:27:44 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	printf_info(t_info *info)
{
	printf("===============\n");
	printf("fork %p\n", info->fork);
	printf("fork_mutex %p\n", info->fork_mutex);
	printf("philo %d\n", info->philo_cnt);
	printf("lifespan %d\n", info->lifespan);
	printf("eat_time %d\n", info->eat_time);
	printf("sleep_time %d\n", info->sleep_time);
	// printf("think_time %d\n", info->think_time);
	printf("min_eat %d\n", info->min_eat);
	printf("===============\n");
}


long ft_atol(const char *str)
{
	long long	result;

	result = 0;
	if (*str == ' ' || *str == '\0' || *str == '-')
		return (-1);
	if (*str == '+')
		str++;
	if (!('0' <= *str && *str <= '9'))
		return (-1);
	while ('0' <= *str && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (*str != '\0')
		return (-1);
	return (result);
}

int	set_info(t_info *info, int argc, char **argv)
{
	long	temp;
	int		i;

	i = 1;
	while (i < argc)
	{
		temp = ft_atol(argv[i]);
		if (temp == -1 || temp > INT_MAX)
			return (-1);
		if (i == 1)
			info->philo_cnt = temp;
		else if (i == 2)
			info->lifespan = temp;
		else if (i == 3)
			info->eat_time = temp;
		else if (i == 4)
			info->sleep_time = temp;
		else if (i == 5)
			info->min_eat = temp;
		i++;
	}
	return (0);
}

//철학자 수, 죽을 시간, 먹는시간, 자는시간, (각 철학자 최소 식사 횟수)
//argc 최대 6

t_info	*parsing(int argc, char **argv)
{
	t_info	*info;

	if (!(argc == 5 || argc == 6))
		return (0);
	info = malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	if (set_info(info, argc, argv) == -1)
		return (NULL);
	if (argc == 5)
		info->min_eat = -1;
	return (info);
}
