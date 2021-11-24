/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:43:18 by atahiri           #+#    #+#             */
/*   Updated: 2021/11/25 00:25:10 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		check_data(t_global *data)
{
	if (data->philos_nb <= 0 || data->time_to_die <= 0
		|| data->time_to_eat <= 0 || data->time_to_eat <= 0)
	{
		return (1);
	}
	if (data->it_must_eat == 1 && data->must_eat_nb <= 0)
		return (1);
	return (0);
}