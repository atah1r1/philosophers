/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:40:00 by atahiri           #+#    #+#             */
/*   Updated: 2021/11/24 12:53:33 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct	s_philo
{
	int		philos_nb;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		must_eat_nb;
}				t_philo;


int		ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
#endif