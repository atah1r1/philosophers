/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 22:26:02 by atahiri           #+#    #+#             */
/*   Updated: 2021/12/12 15:21:30 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

unsigned long long	get_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

void	myusleep(unsigned long long time)
{
	unsigned long long current_time;

	current_time = get_time();
	usleep((time * 1e3) - 10000);
	while (get_time() - current_time < time)
		continue ;
}

unsigned long long	timestamp(t_philo *philo)
{
	return (get_time() - philo->state->start_time);
}