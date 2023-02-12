/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungseok <hyungseok@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:16:42 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/02/12 14:13:43 by hyungseok        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_fork_cursor(int	*cur, int *next, int i, int num_of_philos)
{
	if (i == num_of_philos - 1)
	{
		*cur = i;
		*next = 0;
	}
	else
	{
		*cur = i;
		*next = i + 1;
	} 
}

int	philo_is_full(t_philos *philos)
{
	if (philos->table->must_eat <= 0)
		return (TRUE);
	else if (philos->must_eat == philos->table->must_eat)
		return (FALSE);
	else
		return (TRUE);
}

void	milliseconds(int nanoseconds)
{
	ssize_t	tmp;

	tmp = nanoseconds * 1000;
	usleep(tmp);
}
