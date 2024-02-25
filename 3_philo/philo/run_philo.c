/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:47:58 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/25 22:02:17 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo)
{
	struct timeval	before_eat_time;
	long			eating_time;
	long			diff_time;
	long			lifespan;

	eating_time = 0;
	lifespan = 0;
	diff_time = get_time(philo->start_time);
	philo_print(philo, "is eating", diff_time);
	gettimeofday(&before_eat_time, 0);
	while (eating_time < philo->info->time_to_eat)//이 부분 <, <= 로 수정하고
	{
		usleep(100);
		eating_time = get_time(before_eat_time);
		lifespan = get_time(philo->start_time);
		if (philo->lifespan - lifespan <= 0)//죽음
		{
			printf("%ld %d eat died\n", lifespan, philo->philo_nb);//그냥 died로 수정
			philo->lifespan = 0;
			return ;
		}
	}
	philo->lifespan += philo->info->time_to_die;
	philo->eat_cnt += 1;
}

void	grab_fork(t_philo *philo)
{
	long	diff_time;
	long	lifespan;

	lifespan = 0;
	if (pthread_mutex_lock(&(philo->fork_mutex[philo->left_fork])) == -1)// if로 걸어도 mutex자체가 대기상태로 만들어주니까 상관없을듯
		philo_think(philo);
	philo->fork[philo->left_fork] = 1;
	diff_time = get_time(philo->start_time);
	philo_print(philo, "has taken a fork", diff_time);
	if (philo->info->philo_cnt == 1)
	{
		while (1)
		{
			lifespan = get_time(philo->start_time);
			if (philo->lifespan - lifespan <= 0)
			{
				printf("%ld %d only 1 philo died\n", lifespan, philo->philo_nb);
				philo->lifespan = 0;
				return ;
			}
		}
	}
	lifespan = get_time(philo->start_time);
	if (philo->lifespan - lifespan <= 0)
	{
		lifespan = get_time(philo->start_time);
		printf("fork %ld %d died\n", lifespan, philo->philo_nb);//그냥 died로 수정
		philo->lifespan = 0;
		return ;
	}
	pthread_mutex_lock(&(philo->fork_mutex[philo->right_fork]));
	philo->fork[philo->right_fork] = 1;
	diff_time = get_time(philo->start_time);
	philo_print(philo, "has taken a fork", diff_time);
}

void	drop_fork(t_philo *philo)
{
	philo->fork[philo->left_fork] = 0;
	pthread_mutex_unlock(&(philo->fork_mutex[philo->left_fork]));//unlock 순서 뒤집기
	philo->fork[philo->right_fork] = 0;
	pthread_mutex_unlock(&(philo->fork_mutex[philo->right_fork]));
}

void	philo_behavior(t_philo *philo)
{
	grab_fork(philo);
	if (philo->lifespan == 0)
		return ;
	philo_eat(philo);
	if (philo->eat_cnt == philo->info->min_eat_cnt)
	{
		printf("fulfill min eatcnt\n");
		return ;
	}
	if (philo->lifespan <= 0)
		return ;
	drop_fork(philo);
	philo_sleep(philo);
	if (philo->lifespan <= 0)
		return ;
	philo_think(philo);
	if (philo->lifespan <= 0)
		return ;
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
		philo_behavior(philo);
		if (philo->lifespan <= 0)
			return (NULL);
		usleep(10);
	}
	return (NULL);
}
