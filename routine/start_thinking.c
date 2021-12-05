/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_thinking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 10:44:12 by atahiri           #+#    #+#             */
/*   Updated: 2021/12/05 10:44:52 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	start_thinking(t_philo *philo)
{
	philo->status = THINKING;
	pthread_mutex_lock(&philo->state->printing_lock);
	printf("is thinking");
	pthread_mutex_unlock(&philo->state->printing_lock);
}