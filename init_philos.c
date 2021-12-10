/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:27:29 by atahiri           #+#    #+#             */
/*   Updated: 2021/12/10 17:37:15 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		check_data(t_global *data)
{
	if (data->philos_nb <= 0 || data->time_to_die <= 0
		|| data->time_to_eat <= 0 || data->time_to_sleep <= 0)
	{
		return (1);
	}
	if (data->it_must_eat == 1 && data->must_eat_nb <= 0)
		return (1);
	return (0);
}

t_global	*get_data(int argc, char **argv)
{
	t_global	*data;

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
	return (data);
}

t_philo		*init_philos(int argc, char **argv)
{
	t_philo			*philos;
	t_global		*data;
	int				i;

	data = get_data(argc, argv);


	// printing data
	// printf(">> NB == %d\n TTD == %llu\n TTE === %llu\n TTS == %llu \n",
	// 	data->philos_nb, data->time_to_die, data->time_to_eat, data->time_to_sleep);

	if (check_data(data))
	{
		printf("Error happened on data entered!!\n");
		return (NULL);
	}
	// create mutexes
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philos_nb);
	i = -1;
	while (++i < data->philos_nb)
		pthread_mutex_init(&data->forks[i], NULL);

	// init philos struct
	philos = malloc(sizeof(t_philo) * data->philos_nb);
	i = -1;
	while (++i < data->philos_nb)
	{
		philos[i].id = i;
		philos[i].state = data;
		philos[i].eat = 0;
		philos[i].nb_eats = 0;
		philos[i].last_eat = get_time();
		pthread_mutex_init(&philos[i].eating, NULL);
	}
	return (philos);
}