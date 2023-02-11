/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:15:53 by hyungseok         #+#    #+#             */
/*   Updated: 2023/02/11 14:46:10 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	leakss(void)
{
	system("leaks a.out");
}

int	main(int ac, char **av)
{
	t_table	table;

	args_init(&table, ac, av);
	table_init(&table);
	congression(&table);
	// atexit(leakss);
	return (0);
}
