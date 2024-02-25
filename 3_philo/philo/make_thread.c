/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:57:07 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/15 20:46:22 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*run_philo(void *tmp_philo)
{
	t_philo *philo;
	
	philo = (t_philo *)tmp_philo;
	if (philo->idx % 2 == 0);//짝
	else;//홀
}

void	wait_thread(t_philo *philo, int philo_cnt, struct timeval start_time)
{
	long	diff_usec;
	struct timeval	end_time;
	int	i;

	i = 0;
	while (i < philo_cnt)
	{
		pthread_join(philo[i].tid, 0);
		gettimeofday(&end_time, 0);	// usleep 후 시간 저장
		diff_usec = end_time.tv_usec - start_time.tv_usec;
		printf("%d : sec %lu\n", i, diff_usec);
		i++;
	}
}

void	make_thread(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->philo_cnt)
	{
		pthread_create(&philo[i].tid, 0, run_philo, (void *)philo);
		i++;
	}
}

void	run_thread(t_info *info, t_philo *philo)
{
	struct timeval	start_time;

	gettimeofday(&start_time, 0);
	make_thread(info, philo);
	wait_thread(philo, info->philo_cnt, start_time);
}