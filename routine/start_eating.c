/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 10:27:28 by atahiri           #+#    #+#             */
/*   Updated: 2021/12/05 11:14:14 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

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
	wesleep(philo->state->time_to_eat);
	philo->last_eat = timestamp(philo);
	pthread_mutex_unlock(&philo->state->forks[r]);
	pthread_mutex_unlock(&philo->state->forks[l]);
	pthread_mutex_unlock(&philo->eating);
}