/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:27:24 by atahiri           #+#    #+#             */
/*   Updated: 2021/12/02 14:23:56 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void	*data)
{
	(void)data;
	int i = 0;
	while (1)
	{
		printf("[%d]-------\n", i);
		i++;
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
	// 		free(philos);
	// 		return (0);
	// 	}
	// }
	return (1);
}	