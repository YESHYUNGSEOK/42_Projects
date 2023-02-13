/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:16:42 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/02/13 19:14:47 by hyungnoh         ###   ########.fr       */
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

int	philo_is_alive(void)
{
	return (1);
}

void	milliseconds(int nanoseconds)
{
	int	tmp;

	tmp = nanoseconds * 1000;
	usleep(tmp);
}

int	show_time(t_philos *philos)
{
	gettimeofday(&philos->end, NULL);
	philos->time += (philos->end.tv_sec - philos->start.tv_sec) * 1000 + (philos->end.tv_usec - philos->start.tv_usec) / 1000;
	gettimeofday(&philos->start, NULL);
	return (philos->time);
}

void	free_all(t_table *table, t_philos *philos)
{
	free(table->forks);
	free(table);
	free(philos);
}