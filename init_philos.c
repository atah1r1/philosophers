/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:27:29 by atahiri           #+#    #+#             */
/*   Updated: 2021/12/03 12:17:17 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_global	*get_data(int argc, char **argv)
{
	t_global	*data;
	int			i;

	data = malloc(sizeof(t_global));
	data->philos_nb = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->must_eat_nb = 0;
	data->it_must_eat = 0;
	if (argc == 6)
	{
		data->it_must_eat = 1;
		data->must_eat_nb = ft_atoi(argv[5]);
	}
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philos_nb);
	i = -1;
	while (++i < data->philos_nb)
		pthread_mutex_init(&data->forks[i], NULL);
	return (data);
}

t_philo		*init_philos(int argc, char **argv)
{
	t_philo			*philos;
	t_global		*data;
	int				i;
	struct timeval	now;

	gettimeofday(&now, NULL);
	data = get_data(argc, argv);
	if (check_data(data))
	{
		printf("Error happened on data entered!!\n");
		return (NULL);
	}
	philos = malloc(sizeof(t_global) * data->philos_nb);
	i = -1;
	while (++i < data->philos_nb)
	{
		philos[i].id = i;
		philos[i].state = data;
		philos[i].nb_eats = 0;
		pthread_mutex_init(&philos[i].eating, NULL);
	}
	return (philos);
}