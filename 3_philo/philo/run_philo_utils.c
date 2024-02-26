/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philo_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:13:18 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/26 22:20:58 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	odd_sleep(long sleep_time, struct timeval start_time)
{
	long	tmp;
	long	diff_time;

	tmp = sleep_time / 10;//sleep_time이 1000보다 작으면
	diff_time = 0;
	while (diff_time < tmp)
	{
		usleep(100);
		diff_time = get_time(start_time);
	}
}

void	philo_print(t_philo *philo, char const *str)
{
	long	time_stamp;

	time_stamp = 0;
	pthread_mutex_lock(philo->print_mutex);
	if (philo->lifespan == -1)
	{
		printf("%d philo\n", philo->philo_nb);
		pthread_mutex_unlock(philo->print_mutex);
		return ;
	}
	time_stamp = get_time(philo->start_time);
	printf("%ld %d %s\n", time_stamp, philo->philo_nb, str);
	pthread_mutex_unlock(philo->print_mutex);
}