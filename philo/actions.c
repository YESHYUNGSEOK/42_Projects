/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:58:17 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/02/13 19:28:32 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	meal(t_philos *philos, int cur, int next)
{
	printf("%d %d is eating\n", show_time(philos), cur + 1);
	milliseconds(philos->table->time_to_eat);
	philos->must_eat++;
	philos->table->forks[cur].status = IDLE;
	philos->table->forks[next].status = IDLE;
	philos->status = EATING;
}

void	first_fork(t_philos *philos, int cur)
{
	while (FORK_BEING_USED)
	{
		pthread_mutex_lock(&philos->table->forks[cur].fork);
		if (philos->table->forks[cur].status == IDLE)
		{
			printf("%d %d has taken a fork\n", show_time(philos), cur + 1);
			philos->table->forks[cur].status = USING;
			pthread_mutex_unlock(&philos->table->forks[cur].fork);
			break ;
		}
		else
			pthread_mutex_unlock(&philos->table->forks[cur].fork);
	}
}

void	second_fork(t_philos *philos, int cur, int next)
{
	while (FORK_BEING_USED)
	{
		pthread_mutex_lock(&philos->table->forks[next].fork);
		if (philos->table->forks[next].status == IDLE)
		{
			printf("%d %d has taken a fork\n", show_time(philos), cur + 1);
			philos->table->forks[next].status = USING;
			pthread_mutex_unlock(&philos->table->forks[next].fork);
			break ;
		}
		else
			pthread_mutex_unlock(&philos->table->forks[next].fork);
	}
}

void	start_eating(t_philos *philos, int cur, int next)
{
	first_fork(philos, cur);
	second_fork(philos, cur, next);
	meal(philos, cur, next);
}

void	start_sleeping(t_philos *philos, int cur)
{
	printf("%d %d is sleeping\n", show_time(philos), cur + 1);
	milliseconds(philos->table->time_to_sleep);
	philos->status = SLEEPING;
}

void	start_thinking(t_philos *philos, int cur)
{
	printf("%d %d is thinking\n", show_time(philos), cur + 1);
	usleep(100);
	philos->status = WAITING;
}
