/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   congression.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungseok <hyungseok@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:05:56 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/02/12 22:45:28 by hyungseok        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*callup(void *data)
{
	t_philos		*philos;

	philos = (t_philos *)data;
	if (philos->cur % 2 == 0)
		usleep(100);
	while (philo_is_alive() && philo_is_full(philos))
	{
		start_eating(philos, philos->cur, philos->next);
		start_sleeping(philos, philos->cur);
		start_thinking(philos->cur);
	}
	return (NULL);
}

int	congression(t_table *table, t_philos *philos)
{
	static int	i;

	while (i < table->num_of_philos)
	{
		if (pthread_create(&philos[i].thread, NULL, callup, &philos[i]))
			return (EXIT_FAILURE);
		i++;
		sleep(1);
	}
	return (EXIT_SUCCESS);
}
