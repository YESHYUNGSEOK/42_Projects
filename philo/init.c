/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:01:15 by hyungseok         #+#    #+#             */
/*   Updated: 2023/02/16 14:02:08 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	forks_error(int err_code, t_table *table, t_philos *philos)
{
	if (err_code == OCCURED)
	{
		free_all(table, philos);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	forks_init(t_table *table, t_philos *philos)
{
	int	i;
	int	err_code;

	i = 0;
	err_code = 0;
	table->forks = malloc(sizeof(t_forks) * table->num_of_philos);
	if (!table->forks)
		err_code = OCCURED;
	while (i < table->num_of_philos)
	{
		if (pthread_mutex_init(&table->forks[i].fork, NULL))
		{
			err_code = OCCURED;
			break ;
		}
		table->forks[i].status = IDLE;
		i++;
	}
	if (pthread_mutex_init(&table->die, NULL))
		err_code = OCCURED;
	if (pthread_mutex_init(&table->print, NULL))
		err_code = OCCURED;
	if (forks_error(err_code, table, philos))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	table_error(int err_code, t_table *table)
{
	if (err_code == OCCURED)
	{
		free(table);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	table_init(t_table *table, int ac, char **av)
{
	int	err_code;

	err_code = 0;
	if (ac != 5 && ac != 6)
		err_code = OCCURED;
	table->num_of_philos = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	if (table->num_of_philos <= 0 || table->time_to_die <= 0
		|| table->time_to_eat <= 0 || table->time_to_sleep <= 0)
		err_code = OCCURED;
	table->must_eat = 0;
	if (ac == 6)
	{
		table->must_eat = ft_atoi(av[5]);
		if (table->must_eat <= 0)
			err_code = OCCURED;
	}
	else
		table->must_eat = -1;
	table->philo_status = ALIVE;
	if (table_error(err_code, table))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	philos_init(t_table *table, t_philos *philos)
{
	int	i;

	i = 0;
	while (i < table->num_of_philos)
	{
		set_fork_cursor(&philos[i].cur, &philos[i].next, \
			i, table->num_of_philos);
		philos[i].status = WAITING;
		if (table->must_eat > 0)
			philos[i].must_eat = 0;
		else
			philos[i].must_eat = -1;
		philos[i].table = table;
		if (!philos[i].table)
		{
			free(table);
			free(philos);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
