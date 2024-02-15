/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_vars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:22:03 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/15 20:42:14 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*set_philo(t_info *info)
{
	t_philo	*philo;
	int		i;

	i = 0;
	info->fork = malloc(sizeof(int) * info->philo_cnt);
	if (!info->fork)
		return (0);
	info->fork_mutex = malloc(sizeof(pthread_mutex_t) * info->philo_cnt);
	if (!info->fork_mutex)
		return (0);
	memset(info->fork, 0, sizeof(int) * info->philo_cnt);
	philo = malloc(sizeof(t_philo) * info->philo_cnt);
	if (!philo)
		return (0);
	while (i < info->philo_cnt)
	{
		if (i == 0)
			philo[i].left_fork = info->philo_cnt - 1 - i;
		else
			philo[i].left_fork = i + 1;
		philo[i].right_fork = i;
		philo[i].idx = i;
		philo[i].fork = info->fork;
		philo[i].fork_mutex = info->fork_mutex;
		i++;
	}
	return (philo);
}
