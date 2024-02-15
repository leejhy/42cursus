/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:57:23 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/15 20:46:46 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <memory.h>
# include <sys/time.h>
# include <pthread.h>

# define INT_MAX 2147483647

typedef struct s_info
{
	pthread_mutex_t	*fork_mutex;
	int				*fork;
	int				philo_cnt;
	int				lifespan;
	int				eat_time;
	int				sleep_time;
	// int				think_time;
	int				min_eat;
}	t_info;

typedef struct s_philo
{
	pthread_t		tid;
	int				idx;
	int				left_fork;
	int				right_fork;
	int				*fork;
	pthread_mutex_t	*fork_mutex;
}	t_philo;

void	printf_info(t_info *info);//

/* parsing.c */
t_info	*parsing(int argc, char **argv);
int		set_info(t_info *info, int argc, char **argv);
long	ft_atol(const char *str);
t_philo	*set_philo(t_info *info);

/* set_vars.c */
void	run_thread(t_info *info, t_philo *philo);

/* make_thread */
void	*run_philo(void *info);
void	run_thread(t_info *info, t_philo *philo);
void	wait_thread(t_philo *philo, int philo_cnt, struct timeval start_time);

#endif