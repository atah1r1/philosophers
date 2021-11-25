/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:27:24 by atahiri           #+#    #+#             */
/*   Updated: 2021/11/25 14:41:10 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine()
{
	pthread_mutex_t mutex;

	pthread_mutex_init(&mutex, NULL);
	pthread_mutex_lock(&mutex);
	printf("routine function\n");
	pthread_mutex_unlock(&mutex);
	return NULL;
}


int		start(pthread_t	*threads, t_philo *philos)
{
	int i;

	i = -1;
	while (++i < philos->state->philos_nb)
		pthread_create(&threads[i], NULL, &routine, NULL);
	return (0);
}	