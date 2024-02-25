/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_thread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:57:07 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/25 21:32:29 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(struct timeval	start_time)
{
	struct timeval	curr_time;
	long	curr_msec;
	long	start_msec;

	gettimeofday(&curr_time, 0);
	curr_msec = curr_time.tv_sec * 1000 + curr_time.tv_usec / 1000;
	start_msec = start_time.tv_sec * 1000 + start_time.tv_usec/1000;
	return (curr_msec - start_msec);
}

void	wait_thread(t_philo *philo, int philo_cnt)
{
	int		i;

	i = 0;
	while (i < philo_cnt)
	{
		pthread_join(philo[i].tid, 0);
		i++;
	}
}

void	make_thread(t_info *info, t_philo *philo)
{
	int	i;
	struct timeval start_time;

	i = 0;
	gettimeofday(&start_time, 0);
	while (i < info->philo_cnt)//5
	{
		philo[i].start_time = start_time;
		pthread_create(&philo[i].tid, 0, run_philo, (void *)(&philo[i]));
		// usleep(100);
		i++;
	}
}

void	run_thread(t_info *info, t_philo *philo)
{
	make_thread(info, philo);
	wait_thread(philo, info->philo_cnt);
}
