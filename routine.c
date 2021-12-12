/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 10:06:55 by atahiri           #+#    #+#             */
/*   Updated: 2021/12/12 12:59:48 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print(int state, t_philo *philo)
{
	pthread_mutex_lock(&philo->state->printing_lock);
	if (state  == 0)
		printf("%lld %d is eating\n", timestamp(philo), philo->id + 1);
	else if (state == 1)
		printf("%lld %d is sleeping\n", timestamp(philo), philo->id + 1);
	else if (state == 2)
		printf("%lld %d is thinking\n", timestamp(philo), philo->id + 1);
	else if (state == 4)
		printf("%lld %d has taken a fork\n", timestamp(philo), philo->id + 1);
	pthread_mutex_unlock(&philo->state->printing_lock);
}

void	start_eating(t_philo *philo)
{
	philo->status = EATING;
	philo->eat = 1;
	pthread_mutex_lock(&philo->eating);

	philo->last_eat = get_time();
	print(EATING, philo);
	pthread_mutex_unlock(&philo->eating);
	
	philo->nb_eats += 1;
	myusleep(philo->state->time_to_eat);
	philo->eat = 0;
	pthread_mutex_unlock(&philo->state->forks[(philo->id + 1) % philo->state->philos_nb]);
	pthread_mutex_unlock(&philo->state->forks[philo->id]);
}

void	start_sleeping(t_philo *philo)
{
	philo->status = SLEEPING;
	print(SLEEPING, philo);
	myusleep(philo->state->time_to_sleep);
}

void	start_thinking(t_philo *philo)
{
	philo->status = THINKING;
	print(THINKING, philo);
}

void		take_forks(t_philo *philo)
{
	if (philo->id % 2 != 0)
	{
		pthread_mutex_lock(&philo->state->forks[(philo->id + 1) % philo->state->philos_nb]);
		print(4, philo);
		pthread_mutex_lock(&philo->state->forks[philo->id]);
		print(4, philo);
	}
	else
	{
		pthread_mutex_lock(&philo->state->forks[philo->id]);
		print(4, philo);
		pthread_mutex_lock(&philo->state->forks[(philo->id + 1) % philo->state->philos_nb]);
		print(4, philo);

	}
}