/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:27:24 by atahiri           #+#    #+#             */
/*   Updated: 2021/12/05 10:45:31 by atahiri          ###   ########.fr       */
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

// int	supervisor(t_philo *philos)
// {
// 	return (1);
// }

int		start(pthread_t	*threads, t_philo *philos)
{
	int			i;
	// pthread_t	super;

	i = -1;
	while (++i < philos->state->philos_nb)
	{
		if (i == 0)
			philos[0].state->start_time = get_time();
		pthread_create(&threads[i], NULL, &routine, &philos[i]);
	}
	// pthread_create(&super, NULL, supervisor, (void *)philos);
	// pthread_join(super, NULL);
	return (1);
}	