/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:57:29 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/26 19:13:23 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_info_philo(t_info *info, t_philo *philo)
{
	printf("%p\n", philo);
	printf("======info=====\n");
	printf("philo_cnt %ld\n", info->philo_cnt);
	printf("time_to_die %ld\n", info->time_to_die);
	printf("time_to_eat %ld\n", info->time_to_eat);
	printf("time_to_sleep %ld\n", info->time_to_sleep);
	printf("min_eat_cnt %ld\n", info->min_eat_cnt);
	printf("===============\n");
	for (int i = 0; i < info->philo_cnt; i++)
	{
		printf("=====philo %d=====\n", philo[i].philo_nb);
		printf("philo tid %p\n", philo[i].tid);
		printf("philo_idx %d\n", philo[i].philo_nb);
		printf("left_fork %d\n", philo[i].left_fork);
		printf("right_fork %d\n", philo[i].right_fork);
		printf("fork arr %p\n", philo[i].fork);
		printf("fork_mutex %p\n", philo[i].fork_mutex);
		printf("===============\n");
	}
}

void	frees(t_info *info, t_philo *philos)
{
	free(info);
	free(philos->fork);
	free(philos->fork_mutex);
	free(philos);
}

//철학자 수, 죽을 시간, 먹는시간, 자는시간, (각 철학자 최소 식사 횟수)
int	main(int argc, char **argv)
{
	t_info		*info;
	t_philo		*philos;

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
	// print_info_philo(info, philo);
	frees(info, philos);
	// system("leaks philo");
	return (0);
}
