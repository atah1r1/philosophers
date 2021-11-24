/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:40:00 by atahiri           #+#    #+#             */
/*   Updated: 2021/11/24 19:39:31 by atahiri          ###   ########.fr       */
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

typedef struct	s_global {
	int					philos_nb;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					must_eat_nb;
	pthread_mutex_t		*forks;
	pthread_mutex_t		printing_lock;
}				t_global;

typedef struct s_philo {
	t_status			status;
	int					id;
	int					nb_eats;
	int					last_eat;
	pthread_mutex_t		eat_lock;
	pthread_t			t_id;
	t_global			*state;
}				t_philo;

int		ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
#endif