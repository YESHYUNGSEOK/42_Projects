/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   congression.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:05:56 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/02/11 17:49:09 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*callup(void *data)
{
	t_table			*table;
	int				cur;
	int				next;

	table = (t_table *)data;
	set_id(table, &cur, &next);
	while (philo_is_alive())
	{
		if (table->philos[cur].status == WAITING)
			start_eating(table, cur, next);
		else if (table->philos[cur].status == EATING)
			start_sleeping(table, cur);
		else if (table->philos[cur].status == SLEEPING)
			start_thinking(table, cur);
	}
	return (NULL);
}

void	congression(t_table *table)
{
	static int	i;
	
	while (i < table->num_of_philos)
	{
		table->id = i;
		pthread_create(&table->philos[i].philo, NULL, callup, (void *)table);
		i++;
		sleep(1);
	}
}
