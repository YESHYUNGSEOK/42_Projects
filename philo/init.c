/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungseok <hyungseok@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:01:15 by hyungseok         #+#    #+#             */
/*   Updated: 2023/02/15 16:34:13 by hyungseok        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	forks_init(t_table *table)
{
	static int	i;

	table->forks = malloc(sizeof(t_forks *) * table->num_of_philos);
	if (!table->forks)
		return (EXIT_FAILURE);
	while (i < table->num_of_philos)
	{
		if (pthread_mutex_init(&table->forks[i].fork, NULL))
			return (EXIT_FAILURE);
		table->forks[i].status = IDLE;
		i++;
	}
	if (pthread_mutex_init(&table->die, NULL))
		return (EXIT_FAILURE);
	if (pthread_mutex_init(&table->print, NULL))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	table_init(t_table *table, int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (EXIT_FAILURE);
	table->num_of_philos = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	if (table->num_of_philos <= 0 || table->time_to_die <= 0 
		|| table->time_to_eat <= 0 || table->time_to_sleep <= 0)
		return (EXIT_FAILURE);
	table->must_eat = 0;
	if (ac == 6)
	{
		table->must_eat = ft_atoi(av[5]);
		if (table->must_eat <= 0)
			return (EXIT_FAILURE);
	}
	else
		table->must_eat = -1;
	table->philo_status = ALIVE;
	return (EXIT_SUCCESS);
}

int	philos_init(t_table *table, t_philos *philos)
{
	static int	i;

	while (i < table->num_of_philos)
	{
		set_fork_cursor(&philos[i].cur, &philos[i].next, i, table->num_of_philos);
		philos[i].status = WAITING;
		if (table->must_eat > 0)
			philos[i].must_eat = 0;
		else
			philos[i].must_eat = -1;
		philos[i].table = table;
		if (!philos[i].table)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
