/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungseok <hyungseok@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:15:53 by hyungseok         #+#    #+#             */
/*   Updated: 2023/02/11 23:44:12 by hyungseok        ###   ########.fr       */
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
	if (!table)
		err_msg("error: memory allocation failure");
	args_init(table, ac, av);
	table_init(table);
	philos = malloc(sizeof(t_philos) * table->num_of_philos);
	if (!philos)
		err_msg("error: memory allocation failure");
	philos_init(table, philos);
	congression(table, philos);
	// atexit(leakss);
	return (0);
}
