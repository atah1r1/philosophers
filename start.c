/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:27:24 by atahiri           #+#    #+#             */
/*   Updated: 2021/12/12 16:37:43 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (1)
	{
		take_forks(philo);
		start_eating(philo);
		start_sleeping(philo);
		start_thinking(philo);
	}
	return (NULL);
}

int	check_number_of_eatings(t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < philos->state->philos_nb)
	{
		if (philos->state->must_eat_nb > philos[i].nb_eats)
			return (0);
	}
	return (1);
}

void	*supervisor(void *philos)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)philos;
	usleep(100);
	while (1)
	{
		i = -1;
		while (++i < philo[0].state->philos_nb)
		{
			if ((get_time() - philo[i].last_eat) > philo[i].state->time_to_die
				&& !philo[i].eat)
			{
				pthread_mutex_lock(&philo[i].eating);
				pthread_mutex_lock(&philo->state->printing_lock);
				printf("%lld %d dead\n", timestamp(philo), philo->id + 1);
				pthread_mutex_unlock(&philo[i].eating);
				return (NULL);
			}
		}
		if (philo->state->it_must_eat == 1 && check_number_of_eatings(philos))
			return (NULL);
		usleep(100);
	}
	return (NULL);
}

int	start(pthread_t *threads, t_philo *philos)
{
	int			i;
	pthread_t	super;

	i = -1;
	while (++i < philos->state->philos_nb)
	{
		if (i == 0)
			philos->state->start_time = get_time();
		pthread_create(&threads[i], NULL, &routine, (void *)&philos[i]);
		usleep(1);
	}
	pthread_create(&super, NULL, supervisor, (void *)philos);
	pthread_join(super, NULL);
	return (1);
}
