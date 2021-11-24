/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:39:28 by atahiri           #+#    #+#             */
/*   Updated: 2021/11/24 13:10:01 by atahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	error_handling(int argc, char **args)
{
	int i;
	int j;

	i = 0;
	if (argc != 6)
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
	if (error_handling(argc, argv))
		printf("Error in arguments\n");
	struct timeval now;
	gettimeofday(&now, NULL);
	printf("%ld", (now.tv_sec * 1000) - (now.tv_usec / 1000));
	return (0);
}