/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungseok <hyungseok@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:58:17 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/02/12 00:04:29 by hyungseok        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_eating(t_philos *philos, int left, int right)
{
	if (pthread_mutex_lock(&philos->table->forks[left].fork) == 0)
	{
		printf("philo_%d has taken a fork.\n", left + 1);
		philos->fork_cnt++;
	}
	if (pthread_mutex_lock(&philos->table->forks[right].fork) == 0)
	{
		printf("philo_%d has taken a fork.\n", left + 1);
		philos->fork_cnt++;
	}
	if (philos->fork_cnt == READY_TO_EAT)
	{
		printf("philo_%d is eating.\n", left + 1);
		pthread_mutex_unlock(&philos->table->forks[left].fork);
		pthread_mutex_unlock(&philos->table->forks[right].fork);
		philos->status = EATING;
		philos->must_eat++;
		philos->fork_cnt = 0;
		milliseconds(philos->table->time_to_eat);
	}
}

void	start_sleeping(t_philos *philos, int left)
{
	printf("philo_%d is sleeping.\n", left + 1);
	philos->status = SLEEPING;
	milliseconds(philos->table->time_to_sleep);
}

void	start_thinking(t_philos *philos, int left)
{
	printf("philo_%d is thinking.\n", left + 1);
	philos->status = WAITING;
	usleep(1);
}

int	philo_is_alive(void)
{
	return (1);
}