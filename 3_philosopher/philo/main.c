/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:57:29 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/15 20:42:27 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_info(t_info *info)
{
	free(info->fork);
	free(info->fork_mutex);
	free(info);
}

//철학자 수, 죽을 시간, 먹는시간, 자는시간, (각 철학자 최소 식사 횟수)
int	main(int argc, char **argv)
{
	t_info		*info;
	t_philo		*philo;

	info = parsing(argc, argv);
	if (!info)
	{
		write(2, "argument error\n", 15);
		return (1);
	}
	philo = set_philo(info);
	philo = malloc(sizeof(t_philo) * info->philo_cnt);
	if (!philo)
		return (0);
	run_thread(info, philo);
	printf_info(info);
	free_info(info);
	// system("leaks philo");
	return (0);
}
