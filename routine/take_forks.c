/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 10:17:28 by atahiri           #+#    #+#             */
/*   Updated: 2021/12/05 10:41:43 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

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
	printf("has taken a fork\n");
	pthread_mutex_unlock(&philo->state->printing_lock);
}