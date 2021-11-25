/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:40:00 by atahiri           #+#    #+#             */
/*   Updated: 2021/11/25 13:31:33 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
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
	unsigned long long	time_to_die;
	unsigned long long	time_to_eat;
	unsigned long long	time_to_sleep;
	int					must_eat_nb;
	int					it_must_eat;
	pthread_mutex_t		*forks;
	pthread_mutex_t		printing_lock;
}				t_global;

typedef struct s_philo {
	t_status			status;
	int					id;
	int					nb_eats;
	unsigned long long	last_eat;
	pthread_t			t_id;
	pthread_mutex_t		eating;
	t_global			*state;
}				t_philo;

int			ft_atoi(const char *str);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
t_philo		*init_philos(int argc, char **argv);
t_global	*get_data(int argc, char **argv);
int			check_data(t_global *data);
int			start(pthread_t	*threads, t_philo *philos);
#endif