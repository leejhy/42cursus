/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_vars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:22:03 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/25 21:31:55 by junhylee         ###   ########.fr       */
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

int	set_philo(t_info *info, t_philo *philo)
{
	int	i;
	pthread_mutex_t	*print_mutex;

	i = 0;
	print_mutex = malloc(sizeof(pthread_mutex_t) * info->philo_cnt);
	if (!print_mutex)
		return (0);
	while (i < info->philo_cnt)
	{
		if (i == 0)
			philo[i].left_fork = info->philo_cnt - 1;
		else
			philo[i].left_fork = i - 1;
		philo[i].right_fork = i;
		philo[i].philo_nb = i + 1;
		philo[i].info = info;
		philo[i].print_mutex = print_mutex;
		philo[i].lifespan = info->time_to_die;
		philo[i].eat_cnt = 0;
		i++;
	}
	return (1);
}

t_philo	*make_philo(t_info *info)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = malloc(sizeof(t_philo) * info->philo_cnt);
	if (!philo)
		return (NULL);
	if (set_fork_mutex(info, philo) == 0)
		return (NULL);
	if (set_philo(info, philo) == 0)
		return (NULL);
	return (philo);
}
