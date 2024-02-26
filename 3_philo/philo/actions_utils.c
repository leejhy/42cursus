/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:54:16 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/26 21:27:57 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	only_one_philo(t_philo *philo)
{
	// long	lifespan;

	while (1)
	{
		// lifespan = get_time(philo->start_time);
		if (is_died(philo) == 1)
			return ;
		usleep(10);
		// pthread_mutex_lock(philo->monitor_mutex);
		// if (philo->lifespan - lifespan <= 0)
		// {
		// 	// philo->fork[philo->left_fork] = 0;
		// 	printf("%ld %d only 1 philo died\n", lifespan, philo->philo_nb);
		// 	// pthread_mutex_unlock(&(philo->fork_mutex[philo->left_fork]));
		// 	philo->lifespan = -1;
		// 	pthread_mutex_unlock(philo->monitor_mutex);
		// 	return ;
		// }
		// pthread_mutex_unlock(philo->monitor_mutex);
	}
}

int		is_died(t_philo *philo)
{
	long	lifespan;

	pthread_mutex_lock(philo->dead_mutex);
	lifespan = get_time(philo->start_time);//mutex_lock이랑 자리 바꾸기 차이 있는지 없는지 체크하기
	if (philo->lifespan - lifespan <= 0)//죽음
	{
		philo->lifespan = -1;
		pthread_mutex_unlock(philo->dead_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->dead_mutex);
	return (0);
}