/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   congression.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungseok <hyungseok@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:05:56 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/02/12 00:07:10 by hyungseok        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*callup(void *data)
{
	t_philos		*philos;

	philos = (t_philos *)data;
	while (philo_is_alive() && philo_is_full(philos))
	{
		if (philos->status == WAITING)
			start_eating(philos, philos->left, philos->right);
		if (philos->status == EATING)
			start_sleeping(philos, philos->left);
		if (philos->status == SLEEPING)
			start_thinking(philos, philos->left);
	}
	return (NULL);
}

void	congression(t_table *table, t_philos *philos)
{
	static int	i;
	
	while (i < table->num_of_philos)
	{
		pthread_create(&philos[i].philo, NULL, callup, &philos[i]);
		i = i + 2;
		sleep(1);
	}
	i = 1;
	while (i < table->num_of_philos)
	{
		pthread_create(&philos[i].philo, NULL, callup, &philos[i]);
		i = i + 2;
		sleep(1);
	}	
}
