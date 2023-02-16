/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:15:53 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/02/16 14:07:45 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_table		*table;
	t_philos	*philos;

	table = malloc(sizeof(t_table));
	if (!table || table_init(table, ac, av))
		return (EXIT_FAILURE);
	philos = malloc(sizeof(t_philos) * table->num_of_philos);
	if (!philos || philos_init(table, philos) || forks_init(table, philos))
		return (EXIT_FAILURE);
	if (congression(table, philos))
	{
		free_all(table, philos);
		return (EXIT_FAILURE);
	}
	free_all(table, philos);
	return (EXIT_SUCCESS);
}
