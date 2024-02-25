/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:57:23 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/25 21:26:02 by junhylee         ###   ########.fr       */
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
	pthread_mutex_t	*start_mutex;
	long			philo_cnt;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			min_eat_cnt;
}	t_info;

typedef struct s_philo
{
	t_info			*info;
	pthread_t		tid;
	struct timeval	start_time;
	int				philo_nb;
	int				left_fork;
	int				right_fork;
	int				*fork;
	long			lifespan;
	long			eat_cnt;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	*print_mutex;
}	t_philo;

/* main.c */
void	frees(t_info *info, t_philo *philo);


/* parsing.c */
t_info	*parsing(int argc, char **argv);
int		set_info(t_info *info, int argc, char **argv);
long	ft_atol(const char *str);
t_philo	*make_philo(t_info *info);

/* set_vars.c */
t_philo	*make_philo(t_info *info);
int	set_philo(t_info *info, t_philo *philo);
int	set_fork_mutex(t_info *info, t_philo *philo);

/* run_thread */
void	run_thread(t_info *info, t_philo *philo);
void	wait_thread(t_philo *philo, int philo_cnt);
void	make_thread(t_info *info, t_philo *philo);
long	get_time(struct timeval	start_time);

/* run_philo.c */
void	*run_philo(void *tmp_philo);
void	philo_behavior(t_philo *philo);
void	drop_fork(t_philo *philo);
void	grab_fork(t_philo *philo);
void	philo_eat(t_philo *philo);

/* run_philo_utils.c */
void	odd_sleep(long sleep_time, struct timeval start_time);
void	philo_print(t_philo *philo, char const *str, long diff_time);

/* behavior.c */
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);

#endif