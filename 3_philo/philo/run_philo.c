/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:47:58 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/27 12:58:36 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_action(t_philo *philo)
{
	if (grab_fork(philo) == 0)
		return (0);
	if (philo_eat(philo) == 0)
		return (0);
	drop_fork(philo);
	if (is_enough_eat(philo) == 1)
		return (0);
	if (philo_sleep(philo) == 0)
		return (0);
	philo_think(philo);
	if (is_died(philo) == 1)
		return (0);
	return (1);
}

void	odd_sleep(long sleep_time, struct timeval start_time)
{
	long	tmp;
	long	diff_time;

	if (sleep_time < 10)
		tmp = 1;
	else
		tmp = sleep_time / 10;
	diff_time = 0;
	while (diff_time < tmp)
	{
		usleep(100);
		diff_time = get_time(start_time);
	}
}

void	*run_philo(void *tmp_philo)
{
	t_philo		*philo;
	long		i;

	i = 0;
	philo = (t_philo *)tmp_philo;
	if (philo->philo_nb % 2 == 1)
		odd_sleep(philo->info->time_to_die, philo->start_time);
	while (1)
	{
		if (philo_action(philo) == 0)
			return (NULL);
		usleep(10);
	}
	return (NULL);
}
