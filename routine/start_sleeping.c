/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sleeping.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 10:42:32 by atahiri           #+#    #+#             */
/*   Updated: 2021/12/05 10:44:41 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	start_sleeping(t_philo *philo)
{
	philo->status = SLEEPING;
	pthread_mutex_lock(&philo->state->printing_lock);
	printf("is sleeping");
	pthread_mutex_unlock(&philo->state->printing_lock);
	wesleep(philo->state->time_to_sleep);
}