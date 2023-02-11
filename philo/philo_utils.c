/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungseok <hyungseok@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:16:42 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/02/12 00:04:46 by hyungseok        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_fork_cursor(int	*left, int *right, int i, int num_of_philos)
{
	if (i == num_of_philos - 1)
	{
		*left = i;
		*right = 0;
	}
	else
	{
		*left = i;
		*right = i + 1;
	} 
}

int	philo_is_full(t_philos *philos)
{
	if (philos->table->must_eat <= 0)
		return (1);
	else if (philos->must_eat == philos->table->must_eat)
		return (0);
	else
		return (1);
}

void	milliseconds(int nanoseconds)
{
	int	i;

	i = -1;
	while (++i < 1000)
		usleep(nanoseconds);
}