/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   congression.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungseok <hyungseok@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:05:56 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/02/15 11:00:16 by hyungseok        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*callup(void *data)
{
	t_philos		*philos;

	philos = (t_philos *)data;
	philos->last_meal = philos->table->start_time;
	if (philos->cur % 2 == 1)
		usleep(500);
	while (philo_is_alive(philos) && philo_is_full(philos))
	{
		if (philos->status == WAITING)
			start_eating(philos, philos->cur, philos->next, philos->cur % 2);
		if (philos->status == EATING)
			start_sleeping(philos, philos->cur);
		if (philos->status == SLEEPING)
			start_thinking(philos, philos->cur);
	}
	return (NULL);
}

int	congression(t_table *table, t_philos *philos)
{
	static int	i;

	table->start_time = get_time();
	while (i < table->num_of_philos)
	{
		if (pthread_create(&philos[i].thread, NULL, callup, &philos[i]))
			return (EXIT_FAILURE);
		i += 2;
	}
	i = 1;
	while (i < table->num_of_philos)
	{
		if (pthread_create(&philos[i].thread, NULL, callup, &philos[i]))
			return (EXIT_FAILURE);
		i += 2;
	}
	i = 0;
	while (i < table->num_of_philos)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	return (EXIT_SUCCESS);
}
