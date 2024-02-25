/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behavior.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:35:47 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/25 19:16:39 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_sleep(t_philo *philo)
{
	struct timeval	before_sleep_time;
	long			sleeping_time;
	long			diff_time;
	long			lifespan;

	sleeping_time = 0;
	gettimeofday(&before_sleep_time, 0);
	diff_time = get_time(philo->start_time);
	philo_print(philo, "is sleeping", diff_time);
	while (sleeping_time < philo->info->time_to_sleep)//이 부분 <, <= 로 수정하고
	{
		usleep(100);
		sleeping_time = get_time(before_sleep_time);
		lifespan = get_time(philo->start_time);
		if (philo->lifespan - lifespan <= 0)//죽음
		{
			philo->lifespan = 0;
			printf("%ld %d died\n", lifespan, philo->philo_nb);
			return ;
		}
	}
}

void	philo_think(t_philo *philo)
{
	struct timeval	before_think_time;
	long			diff_time;

	gettimeofday(&before_think_time, 0);
	diff_time = get_time(philo->start_time);
	philo_print(philo, "is thinking", diff_time);
}
