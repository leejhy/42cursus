/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:47:58 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/26 22:27:19 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_action(t_philo *philo)
{
	if (grab_fork(philo) == 0)//얘는 안에서 is_died 처리해줌
		return (0);
	
	pthread_mutex_lock(philo->min_eat_mutex);
	if (philo->eat_cnt == philo->info->min_eat_cnt)
	{
		drop_fork(philo);
		pthread_mutex_unlock(philo->min_eat_mutex);
		return (0);
	}
	pthread_mutex_unlock(philo->min_eat_mutex);

	
	if (philo_eat(philo) == 0)//먹다가 죽으면
		return (0);
	drop_fork(philo);

	pthread_mutex_lock(philo->min_eat_mutex);
	if (philo->eat_cnt == philo->info->min_eat_cnt)
	{
		pthread_mutex_unlock(philo->min_eat_mutex);
		return (0);
	}
	pthread_mutex_unlock(philo->min_eat_mutex);

	
	if (philo_sleep(philo) == 0)//자다가 죽으면
		return (0);
	philo_think(philo);
	return (1);
}

void	*run_philo(void *tmp_philo)
{
	t_philo		*philo;
	long		i;

	i = 0;
	philo = (t_philo *)tmp_philo;
	if (philo->philo_nb % 2 == 1)//짝수부터 잡을거니까 홀수 슬립
		odd_sleep(philo->info->time_to_die, philo->start_time);//이거 짝수가 첫번째 밥먹을 시간동안 쉬면안되나? 아닌데..
	while (1)
	{
		if (philo_action(philo) == 0)
			return (NULL);
		// if (philo->eat_cnt == philo->info->min_eat_cnt)
		// 	return (NULL);
		usleep(10);
	}
	return (NULL);
}
