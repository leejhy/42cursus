/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_vars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:22:03 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/26 21:32:50 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_fork_mutex(t_info *info, t_philo *philo)
{
	int	i;
	int	*fork;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	*start_mutex;

	i = 0;
	fork = malloc(sizeof(int) * info->philo_cnt);
	if (!fork)
		return (0);
	memset(fork, 0, sizeof(int) * info->philo_cnt);
	fork_mutex = malloc(sizeof(pthread_mutex_t) * info->philo_cnt);
	start_mutex = malloc(sizeof(pthread_mutex_t) * info->philo_cnt);
	if (!start_mutex || !fork_mutex)
		return (0);
	pthread_mutex_init(start_mutex, 0);
	info->start_mutex = start_mutex;
	while (i < info->philo_cnt)
	{
		pthread_mutex_init(&fork_mutex[i], 0);
		philo[i].fork = fork;
		philo[i].fork_mutex = fork_mutex;
		i++;
	}
	return (1);
}

int	set_philo(t_info *info, t_philo *philos)
{
	int	i;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*monitor_mutex;
	pthread_mutex_t	*min_eat_mutex;
	i = 0;
	print_mutex = malloc(sizeof(pthread_mutex_t));
	monitor_mutex = malloc(sizeof(pthread_mutex_t));
	min_eat_mutex = malloc(sizeof(pthread_mutex_t));
	if (!print_mutex || !monitor_mutex)
		return (0);
	pthread_mutex_init(print_mutex, 0);
	pthread_mutex_init(monitor_mutex, 0);
	pthread_mutex_init(min_eat_mutex, 0);
	while (i < info->philo_cnt)
	{
		if (i == 0)
			philos[i].left_fork = info->philo_cnt - 1;
		else
			philos[i].left_fork = i - 1;
		philos[i].right_fork = i;
		philos[i].philo_nb = i + 1;
		philos[i].info = info;
		philos[i].print_mutex = print_mutex;
		philos[i].dead_mutex = monitor_mutex;
		philos[i].min_eat_mutex = min_eat_mutex;
		philos[i].lifespan = info->time_to_die;
		philos[i].eat_cnt = 0;
		i++;
	}
	return (1);
}

t_philo	*make_philo(t_info *info)
{
	t_philo	*philos;
	int		i;

	i = 0;
	philos = malloc(sizeof(t_philo) * info->philo_cnt);
	if (!philos)
		return (NULL);
	if (set_fork_mutex(info, philos) == 0)
		return (NULL);
	if (set_philo(info, philos) == 0)
		return (NULL);
	return (philos);
}
