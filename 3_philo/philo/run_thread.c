/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_thread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:57:07 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/26 22:27:53 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(struct timeval	start_time)
{
	struct timeval	curr_time;
	long	curr_msec;
	long	start_msec;
	long	diff_msec;

	start_msec = (start_time.tv_sec * 1000) + (start_time.tv_usec / 1000);
	gettimeofday(&curr_time, 0);
	curr_msec = (curr_time.tv_sec * 1000) + (curr_time.tv_usec / 1000);
	diff_msec = curr_msec - start_msec;
	return (diff_msec);
}

void	join_thread(t_philo *philo, int philo_cnt)
{
	int		i;

	i = 0;
	while (i < philo_cnt)
	{
		pthread_join(philo[i].tid, 0);
		i++;
	}
}

void	make_thread(t_philo *philos, int philo_cnt)
{
	int				i;
	struct timeval	start_time;

	i = 0;
	gettimeofday(&start_time, 0);
	while (i < philo_cnt)//5
	{
		philos[i].start_time = start_time;
		pthread_create(&philos[i].tid, 0, run_philo, &(philos[i]));
		i++;
	}
}

void	monitor_thread(t_philo *philos, int philo_cnt, int min_eat_cnt)
{
	int	i;

	i = 0;
	while (1)
	{
		i = 0;
		while (i < philo_cnt)//죽었는지 체크
		{
			pthread_mutex_lock(philos[i].dead_mutex);
			if (philos[i].lifespan == -1)//if died philosophers
			{
				pthread_mutex_lock(philos[i].print_mutex);
				printf("%ld %d died\n", get_time(philos[i].start_time), i + 1);
				// usleep(100);
				// for (int j = 0; j < philo_cnt; j++)
				// {
				// 	printf("%d\n", j);
				// 	philos[j].lifespan = -1;
				// }
				pthread_mutex_unlock(philos[i].print_mutex);
				pthread_mutex_unlock(philos[i].dead_mutex);
				return ;
			}
			pthread_mutex_unlock(philos[i].dead_mutex);
			pthread_mutex_lock(philos[i].min_eat_mutex);
			if (philos[i].eat_cnt == min_eat_cnt)//이것도 뮤텍스보호 해야함
			{
				pthread_mutex_unlock(philos[i].min_eat_mutex);
				return ;
			}
			pthread_mutex_unlock(philos[i].min_eat_mutex);
			i++;
		}
		usleep(10);//usleep100으로 돌리니까 섞임
	}
}

void	run_thread(t_info *info, t_philo *philos)
{
	make_thread(philos, info->philo_cnt);
	monitor_thread(philos, info->philo_cnt, info->min_eat_cnt);
	join_thread(philos, info->philo_cnt);
}
