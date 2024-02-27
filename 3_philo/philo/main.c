/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:57:29 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/27 13:54:54 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	frees(t_info *info, t_philo *philos)
{
	free(philos->fork);
	free(philos->fork_mutex);
	free(philos[0].dead_mutex);
	free(philos[0].min_eat_mutex);
	free(philos[0].print_mutex);
	free(info);
	free(philos);
}

void	mutex_destroys(t_philo *philos, int philo_cnt)
{
	int				i;
	pthread_mutex_t	*fork;

	i = 0;
	fork = philos[0].fork_mutex;
	while (i < philo_cnt)
	{
		pthread_mutex_destroy(&fork[i]);
		i++;
	}
	pthread_mutex_destroy(philos[0].dead_mutex);
	pthread_mutex_destroy(philos[0].min_eat_mutex);
	pthread_mutex_destroy(philos[0].print_mutex);
}

int	main(int argc, char **argv)
{
	t_info		*info;
	t_philo		*philos;
	int			i;

	i = 0;
	info = parsing(argc, argv);
	if (!info)
	{
		write(2, "argument error\n", 15);
		return (1);
	}
	philos = make_philo(info);
	if (!philos)
		return (0);
	run_thread(info, philos);
	mutex_destroys(philos, info->philo_cnt);
	frees(info, philos);
	return (0);
}
