/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungseok <hyungseok@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:01:15 by hyungseok         #+#    #+#             */
/*   Updated: 2023/02/11 23:45:04 by hyungseok        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	args_init(t_table *table, int ac, char **av)
{
	if (ac != 5 && ac != 6)
		err_msg("error: invalid arguments");
	table->num_of_philos = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	if (table->num_of_philos <= 0 || table->time_to_die <= 0 
		|| table->time_to_eat <= 0 || table->time_to_sleep <= 0)
		err_msg("error: invalid arguments");
	table->must_eat = 0;
	if (ac == 6)
	{
		table->must_eat = ft_atoi(av[5]);
		if (table->must_eat <= 0)
			err_msg("error: invalid arguments");
	}
	else
		table->must_eat = -1;
}

void	table_init(t_table *table)
{
	static int	i;
	int			tmp;

	tmp = table->num_of_philos;
	table->forks = malloc(sizeof(t_forks *) * table->num_of_philos);
	if (!table->forks)
		err_msg("error: memory allocation failure");
	while (i < table->num_of_philos)
	{
		if (pthread_mutex_init(&table->forks[i].fork, NULL))
			err_msg("error: mutex initialize failure");
		i++;
	}
	table->num_of_philos = tmp;
}

void	philos_init(t_table *table, t_philos *philos)
{
	static int	i;

	while (i < table->num_of_philos)
	{
		set_fork_cursor(&philos[i].left, &philos[i].right, i, table->num_of_philos);
		philos[i].status = WAITING;
		philos[i].fork_cnt = 0;
		if (table->must_eat > 0)
			philos[i].must_eat = 0;
		else
			philos[i].must_eat = -1;
		philos[i].table = table;
		if (!philos[i].table)
			err_msg("error: memory allocation failure");
		i++;
	}
}
