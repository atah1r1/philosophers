/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:40:00 by atahiri           #+#    #+#             */
/*   Updated: 2021/12/09 15:22:22 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

typedef enum s_status {
	EATING,
	SLEEPING,
	THINKING,
	DEAD
}			t_status;

typedef struct	s_global 
{
	int					philos_nb;
	unsigned long long	start_time;
	unsigned long long	time_to_die;
	unsigned long long	time_to_eat;
	unsigned long long	time_to_sleep;
	int					must_eat_nb;
	int 				it_must_eat;
	pthread_mutex_t		*forks;
	pthread_mutex_t		printing_lock;
}				t_global;

typedef struct s_philo {
	t_status			status;
	int					id;
	int					nb_eats;
	unsigned long long	last_eat;
	pthread_mutex_t		eating;
	t_global			*state;
}				t_philo;

int					ft_atoi(const char *str);
int					ft_isdigit(int c);
t_philo				*init_philos(int argc, char **argv);
t_global			*get_data(int argc, char **argv);
int					check_data(t_global *data);
int					start(pthread_t	*threads, t_philo *philos);
void				take_forks(t_philo *philo);
void				start_eating(t_philo *philo);
void				start_sleeping(t_philo *philo);
void				start_thinking(t_philo *philo);
unsigned long long	timestamp(t_philo *philo);
void				wesleep(unsigned long long time);
unsigned long long	get_time(void);
#endif