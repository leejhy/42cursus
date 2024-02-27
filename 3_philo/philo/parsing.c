/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:25:25 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/27 13:46:32 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

long	ft_atol(const char *str)
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
			info->time_to_die = temp;
		else if (i == 3)
			info->time_to_eat = temp;
		else if (i == 4)
			info->time_to_sleep = temp;
		else if (i == 5)
			info->min_eat_cnt = temp;
		i++;
	}
	return (0);
}

t_info	*parsing(int argc, char **argv)
{
	t_info	*info;
	int		i;

	i = 1;
	if (!(argc == 5 || argc == 6))
		return (0);
	info = malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	while (i < argc)
	{
		if (ft_strlen(argv[i]) > 11)
			return (0);
		i++;
	}
	if (set_info(info, argc, argv) == -1)
		return (NULL);
	if (argc == 5)
		info->min_eat_cnt = -1;
	return (info);
}
