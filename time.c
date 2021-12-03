/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 22:26:02 by atahiri           #+#    #+#             */
/*   Updated: 2021/12/03 12:23:59 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

unsigned long long	get_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

void	wesleep(unsigned long long time)
{
	unsigned long long	end;

	end = get_time() + time;
	while (get_time() < end)
		usleep(100);
}

unsigned long long	timestamp(t_philo *philo)
{
	return (get_time() - philo->state->start_time);
}