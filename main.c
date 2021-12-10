/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:39:28 by atahiri           #+#    #+#             */
/*   Updated: 2021/12/10 16:04:45 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	error_handling(int argc, char **args)
{
	int i;
	int j;

	i = 0;
	if (argc != 5 && argc != 6)
		return (1);
	while (args[++i])
	{
		j = -1;
		while (args[i][++j])
		{
			if (!ft_isdigit(args[i][j]))
				return (1);
		}
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_philo		*philos;
	pthread_t	*threads;
	int			i;

	if (error_handling(argc, argv))
	{
		printf("Error in arguments\n");
		return (1);
	}
	else
		philos = init_philos(argc, argv);
	if (!philos)
		return (1);
	threads = malloc(sizeof(pthread_t) * philos->state->philos_nb);
	i = -1;
	while (++i < philos->state->philos_nb)
		pthread_mutex_init(&philos->state->forks[i], NULL);
	if (start(threads, philos) == 0)
		return (0);
	return (0);
}