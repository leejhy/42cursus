/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:35:47 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/26 22:24:23 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	grab_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->fork_mutex[philo->left_fork]));
	philo->fork[philo->left_fork] = 1;
	philo_print(philo, "has taken a fork");
	if (philo->info->philo_cnt == 1)
	{
		only_one_philo(philo);
		return (0);
	}
	if (is_died(philo) == 1)
		return (0);
	pthread_mutex_lock(&(philo->fork_mutex[philo->right_fork]));
	philo->fork[philo->right_fork] = 1;
	philo_print(philo, "has taken a fork");
	return (1);
}

void	drop_fork(t_philo *philo)
{
	philo->fork[philo->left_fork] = 0;
	pthread_mutex_unlock(&(philo->fork_mutex[philo->left_fork]));//unlock 순서 뒤집기
	philo->fork[philo->right_fork] = 0;
	pthread_mutex_unlock(&(philo->fork_mutex[philo->right_fork]));
}

int	philo_sleep(t_philo *philo)
{
	struct timeval	before_sleep_time;
	long			sleeping_time;

	sleeping_time = 0;
	gettimeofday(&before_sleep_time, 0);
	philo_print(philo, "is sleeping");
	while (sleeping_time < philo->info->time_to_sleep)//이 부분 <, <= 로 수정하고
	{
		usleep(100);
		sleeping_time = get_time(before_sleep_time);
		if (is_died(philo) == 1)//자다가 죽음
			return (0);
	}
	return (1);
}

void	philo_think(t_philo *philo)
{
	struct timeval	before_think_time;

	gettimeofday(&before_think_time, 0);
	philo_print(philo, "is thinking");
}

int	philo_eat(t_philo *philo)
{
	struct timeval	before_eat_time;
	long			eating_time;
	long			diff_time;

	eating_time = 0;
	diff_time = get_time(philo->start_time);
	philo_print(philo, "is eating");
	gettimeofday(&before_eat_time, 0);
	while (eating_time < philo->info->time_to_eat)//이 부분 <, <= 로 수정하고
	{
		usleep(100);
		eating_time = get_time(before_eat_time);
		if (is_died(philo) == 1)//먹다가 죽음
			return (0);
	}
	if (is_died(philo) == 1)//먹다가 죽음
		return (0);
	pthread_mutex_lock(philo->dead_mutex);
	philo->lifespan += philo->info->time_to_die;
	pthread_mutex_unlock(philo->dead_mutex);
	if (is_died(philo) == 1)//먹다가 죽음
		return (0);
	pthread_mutex_lock(philo->min_eat_mutex);
	philo->eat_cnt += 1;
	pthread_mutex_unlock(philo->min_eat_mutex);
	return (1);
}
