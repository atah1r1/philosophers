/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:27:24 by atahiri           #+#    #+#             */
/*   Updated: 2021/12/09 11:41:02 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void	*data)
{
	t_philo	*philo;
	// int		id;

	philo = (t_philo *)data;
	while (1)
	{
		take_forks(philo);
		start_eating(philo);
		start_sleeping(philo);
		start_thinking(philo);
	}
	return NULL;
}

void	*supervisor(void *philos)
{
	t_philo			*philo;
	int				time;
	int				i;

	philo = (t_philo *)philos;
	while (1)
	{
		i = -1;
		while (++i < philo[0].state->philos_nb)
		{
			time = timestamp(philo) - philo[i].state->start_time;
			if ((time - philo[i].last_eat) >= philo[i].state->time_to_die
				&& philo[i].status != EATING)
			{
				pthread_mutex_lock(&philo->state->printing_lock);
				pthread_mutex_lock(&philo[i].eating);
				printf("%lld %d dead", timestamp(philo), philo->id + 1);
				return (NULL);
			}
		}
	}
	return (NULL);
}

int		start(pthread_t	*threads, t_philo *philos)
{
	int			i;
	pthread_t	super;

	i = -1;
	while (++i < philos->state->philos_nb)
	{
		if (i == 0)
			philos[0].state->start_time = get_time();
		pthread_create(&threads[i], NULL, &routine, &philos[i]);
	}
	pthread_create(&super, NULL, supervisor, (void *)philos);
	pthread_join(super, NULL);
	i = -1;
	while (++i < philos->state->philos_nb)
		pthread_mutex_destroy(&philos[0].state->forks[i]);
	return (1);
}	