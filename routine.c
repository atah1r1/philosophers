/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 10:06:55 by atahiri           #+#    #+#             */
/*   Updated: 2021/12/10 15:12:58 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	start_eating(t_philo *philo)
{
	int	r;
	int	l;

	r = (philo->id + 1) % philo->state->philos_nb;
	l = philo->id;
	philo->status = EATING;
	pthread_mutex_lock(&philo->eating);
	pthread_mutex_lock(&philo->state->printing_lock);
	printf("%lld %d is eating\n", timestamp(philo), philo->id + 1);
	pthread_mutex_unlock(&philo->state->printing_lock);
	philo->nb_eats += 1;
	myusleep(philo->state->time_to_eat);
	philo->last_eat = timestamp(philo);
	pthread_mutex_unlock(&philo->state->forks[r]);
	pthread_mutex_unlock(&philo->state->forks[l]);
	pthread_mutex_unlock(&philo->eating);
}

void	start_sleeping(t_philo *philo)
{
	philo->status = SLEEPING;
	pthread_mutex_lock(&philo->state->printing_lock);
	printf("%lld %d is sleeping\n", timestamp(philo), philo->id + 1);
	pthread_mutex_unlock(&philo->state->printing_lock);
	myusleep(philo->state->time_to_sleep);
}

void	start_thinking(t_philo *philo)
{
	philo->status = THINKING;
	pthread_mutex_lock(&philo->state->printing_lock);
	printf("%lld %d is thinking\n", timestamp(philo), philo->id + 1);
	pthread_mutex_unlock(&philo->state->printing_lock);
}

void		take_forks(t_philo *philo)
{
	int		r;
	int		l;

	r = (philo->id + 1) % philo->state->philos_nb;
	l = philo->id;
	if ((philo->id + 1) % 2 == 0)
	{
		pthread_mutex_lock(&philo->state->forks[r]);
		pthread_mutex_lock(&philo->state->forks[l]);
	}
	else
	{
		pthread_mutex_lock(&philo->state->forks[l]);
		pthread_mutex_lock(&philo->state->forks[r]);
	}
	pthread_mutex_lock(&philo->state->printing_lock);
	printf("%lld %d has taken a fork\n", timestamp(philo), philo->id + 1);
	pthread_mutex_unlock(&philo->state->printing_lock);
}