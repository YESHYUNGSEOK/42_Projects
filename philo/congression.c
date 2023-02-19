/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   congression.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungseok <hyungseok@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:05:56 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/02/19 17:22:09 by hyungseok        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*callup(void *data)
{
	t_philos		*philos;

	philos = (t_philos *)data;
	philos->last_meal = philos->table->start_time;
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

int	even_eat_first(t_table *table, t_philos *philos)
{
	int	i;

	i = 0;
	table->start_time = get_time();
	while (i < table->num_of_philos)
	{
		if (pthread_create(&philos[i].thread, NULL, callup, &philos[i]))
		{
			while (i)
			{
				pthread_join(philos[i].thread, NULL);
				i -= 2;
			}
			return (EXIT_FAILURE);
		}
		i += 2;
	}
	usleep(500 * table->time_to_eat);
	return (EXIT_SUCCESS);
}

int	congression(t_table *table, t_philos *philos)
{
	int	i;

	if (even_eat_first(table, philos))
		return (EXIT_FAILURE);
	i = 1;
	while (i < table->num_of_philos)
	{
		if (pthread_create(&philos[i].thread, NULL, callup, &philos[i]))
		{
			while (i)
			{
				pthread_join(philos[i].thread, NULL);
				i -= 2;
			}
			return (EXIT_FAILURE);
		}
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
