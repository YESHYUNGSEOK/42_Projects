/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungseok <hyungseok@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:15:53 by hyungseok         #+#    #+#             */
/*   Updated: 2023/02/12 22:00:15 by hyungseok        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	leakss(void)
{
	system("leaks a.out");
}

int	main(int ac, char **av)
{
	t_table		*table;
	t_philos	*philos;
	
	table = malloc(sizeof(t_table));
	if (!table || table_init(table, ac, av))
		return (EXIT_FAILURE);
	philos = malloc(sizeof(t_philos) * table->num_of_philos);
	if (!philos || philos_init(table, philos))
		return (EXIT_FAILURE);
	if (congression(table, philos))
		return (EXIT_FAILURE);
	// atexit(leakss);
	return (EXIT_SUCCESS);
}
