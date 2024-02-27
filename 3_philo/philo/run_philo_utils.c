/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philo_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:54:16 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/27 11:43:49 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_print(t_philo *philo, char const *str)
{
	long	time_stamp;

	time_stamp = 0;
	pthread_mutex_lock(philo->print_mutex);
	if (philo->lifespan == -1)
	{
		pthread_mutex_unlock(philo->print_mutex);
		return ;
	}
	time_stamp = get_time(philo->start_time);
	printf("%ld %d %s\n", time_stamp, philo->philo_nb, str);
	pthread_mutex_unlock(philo->print_mutex);
}

void	only_one_philo(t_philo *philo)
{
	while (1)
	{
		if (is_died(philo) == 1)
		{
			pthread_mutex_unlock(&(philo->fork_mutex[philo->left_fork]));
			return ;
		}
		usleep(10);
	}
}

int	is_died(t_philo *philo)
{
	long	lifespan;

	pthread_mutex_lock(philo->dead_mutex);
	lifespan = get_time(philo->start_time);
	if (philo->lifespan - lifespan <= 0)
	{
		philo->lifespan = -1;
		pthread_mutex_unlock(philo->dead_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->dead_mutex);
	return (0);
}

int	is_enough_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->min_eat_mutex);
	if (philo->eat_cnt == philo->info->min_eat_cnt)
	{
		pthread_mutex_unlock(philo->min_eat_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->min_eat_mutex);
	return (0);
}
