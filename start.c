/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:27:24 by atahiri           #+#    #+#             */
/*   Updated: 2021/12/03 12:22:26 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void	*data)
{
	t_philo	*philo;
	int		id;

	philo = (t_philo *)data;
	if (philo->id % 2 != 0)
		usleep(100);
	id = (philo->id + 1) % philo->state->philos_nb;
	philo->start_eating = get_time();
	while (1)
	{
		// locking_forks(philo, id);
		if (pthread_mutex_lock(&philo->state->forks[philo->id]) == 0)
			{
				pthread_mutex_lock(&philo->state->printing_lock);
				printf("%lld %d has taken a fork\n", timestamp(philo), philo->id);
				pthread_mutex_unlock(&philo->state->printing_lock);
			}
		if (pthread_mutex_lock(&philo->state->forks[id]) == 0)
			{
				pthread_mutex_lock(&philo->state->printing_lock);
				printf("%lld %d has taken a fork\n", timestamp(philo), philo->id);
				pthread_mutex_unlock(&philo->state->printing_lock);
			}
		pthread_mutex_lock(&philo[philo->id].eating);
		pthread_mutex_lock(&philo->state->printing_lock);
		printf("%lld %d is eating\n", timestamp(philo), philo->id);
		pthread_mutex_unlock(&philo->state->printing_lock);
		philo->start_eating = get_time();
		wesleep(philo->state->time_to_eat);
		// unlocking_forks(philo, id);
		pthread_mutex_unlock(&philo->state->forks[philo->id]);
		pthread_mutex_unlock(&philo->state->forks[id]);
		pthread_mutex_unlock(&philo[philo->id].eating);
		philo->nb_eats++;
		pthread_mutex_lock(&philo->state->printing_lock);
		printf("%lld %d is sleeping\n", timestamp(philo), philo->id);
		pthread_mutex_unlock(&philo->state->printing_lock);
		wesleep(philo->state->time_to_sleep);
		pthread_mutex_lock(&philo->state->printing_lock);
		printf("%lld %d is thinking\n", timestamp(philo), philo->id);
		pthread_mutex_unlock(&philo->state->printing_lock);
	}
	return NULL;
}

// int	supervisor(t_philo *philos)
// {
// 	return (1);
// }

int		start(pthread_t	*threads, t_philo *philos)
{
	int i;

	i = -1;
	while (++i < philos->state->philos_nb)
	{
		if (i == 0)
			philos[0].state->start_time = get_time();
		pthread_create(&threads[i], NULL, &routine, &philos[i]);
	}
	// while (1)
	// {
	// 	if (supervisor(philos) == 0)
	// 	{
	// 		free(threads);
	// 		return (0);
	// 	}
	// }
	return (1);
}	