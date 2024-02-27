/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_thread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:57:07 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/27 12:43:58 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(struct timeval start_time)
{
	struct timeval	curr_time;
	long			curr_msec;
	long			start_msec;
	long			diff_msec;

	start_msec = (start_time.tv_sec * 1000) + (start_time.tv_usec / 1000);
	gettimeofday(&curr_time, 0);
	curr_msec = (curr_time.tv_sec * 1000) + (curr_time.tv_usec / 1000);
	diff_msec = curr_msec - start_msec;
	return (diff_msec);
}

int	check_died(t_philo *philos, int philo_cnt, int idx)
{
	int	i;

	i = 0;
	pthread_mutex_lock(philos[idx].dead_mutex);
	if (philos[idx].lifespan == -1)
	{
		pthread_mutex_lock(philos[idx].print_mutex);
		printf("%ld %d died\n", get_time(philos[idx].start_time), idx + 1);
		while (i < philo_cnt)
		{
			philos[i].lifespan = -1;
			i++;
		}
		pthread_mutex_unlock(philos[idx].print_mutex);
		pthread_mutex_unlock(philos[idx].dead_mutex);
		return (1);
	}
	return (0);
}

void	monitor_thread(t_philo *philos, int philo_cnt, int min_eat_cnt)
{
	int	i;

	i = 0;
	while (1)
	{
		i = 0;
		while (i < philo_cnt)
		{
			if (check_died(philos, philo_cnt, i) == 1)
				return ;
			pthread_mutex_unlock(philos[i].dead_mutex);
			pthread_mutex_lock(philos[i].min_eat_mutex);
			if (philos[i].eat_cnt == min_eat_cnt)
			{
				pthread_mutex_unlock(philos[i].min_eat_mutex);
				return ;
			}
			pthread_mutex_unlock(philos[i].min_eat_mutex);
			i++;
		}
		usleep(10);
	}
}

void	run_thread(t_info *info, t_philo *philos)
{
	int				i;
	struct timeval	start_time;

	i = 0;
	gettimeofday(&start_time, 0);
	while (i < info->philo_cnt)
	{
		philos[i].start_time = start_time;
		pthread_create(&philos[i].tid, 0, run_philo, &(philos[i]));
		i++;
	}
	monitor_thread(philos, info->philo_cnt, info->min_eat_cnt);
	i = 0;
	while (i < info->philo_cnt)
	{
		pthread_join(philos[i].tid, 0);
		i++;
	}
}
