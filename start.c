/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:27:24 by atahiri           #+#    #+#             */
/*   Updated: 2021/12/12 12:33:26 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *routine(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;
	while (1)
	{
		// puts("here");
		take_forks(philo);
		start_eating(philo);
		start_sleeping(philo);
		start_thinking(philo);
	}
	return NULL;
}

int check_number_of_eatings(t_philo *philos)
{
	int i = -1;

	while (++i < philos->state->philos_nb)
	{
		if (philos->state->must_eat_nb > philos[i].nb_eats)
		{
			return (0);
		}
			// printf("MUST EAT NB === %d\n", philos[i].nb_eats);
	}
	return (1);
}

void *supervisor(void *philos)
{
	t_philo *philo;
	int i;

	philo = (t_philo *)philos;
	// printf ("nb %d\n", philo[0].state->philos_nb);
	
	while (1)
	{
		i = 0;
		while (i < philo[0].state->philos_nb)
		{
			// printf ("id %d \ntime : %lld\n,  last: %lld\n , start: %lld\n, status %d\n",philo[i].id,
			// (get_time() - philo[i].last_eat), philo[i].last_eat, get_time(), philo[i].status);

			if ((get_time() - philo[i].last_eat) > philo[i].state->time_to_die && !philo[i].eat)
			{
				pthread_mutex_lock(&philo->state->printing_lock);
				pthread_mutex_lock(&philo[i].eating);
				printf("%lld %d dead\n", timestamp(philo), philo->id + 1);
				return (NULL);
			}
			if (philo->state->it_must_eat == 1 && check_number_of_eatings(philos))
			{
				// pthread_mutex_lock(&philo->state->printing_lock);
				// printf("all the philosopher has eaten at least %d times each.", philo->state->must_eat_nb);
				return (NULL);
			}
			i++;
		}
		usleep(100);
	}
	return (NULL);
}

int start(pthread_t *threads, t_philo *philos)
{
	puts("start");
	int i;
	pthread_t super;

	i = -1;
	while (++i < philos->state->philos_nb)
	{
		if (i == 0)
			philos->state->start_time = get_time();
		pthread_create(&threads[i], NULL, &routine, &philos[i]);
	}
	pthread_create(&super, NULL, supervisor, (void *)philos);
	pthread_join(super, NULL);
	return (1);
}