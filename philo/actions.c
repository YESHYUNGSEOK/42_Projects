/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungseok <hyungseok@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:58:17 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/02/12 22:49:38 by hyungseok        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_eating_odd(t_philos *philos, int cur, int next)
{

	if (pthread_mutex_lock(&philos->table->forks[next].fork) == 0)
	{
		printf("%d has taken a fork.\n", cur + 1);
		philos->forks_cnt++;
	}
	if (pthread_mutex_lock(&philos->table->forks[cur].fork) == 0)
	{
		printf("%d has taken a fork.\n", cur + 1);
		philos->forks_cnt++;
	}
	if (philos->forks_cnt == 2)
	{
		printf("%d is eating.\n", cur + 1);
		milliseconds(philos->table->time_to_eat);
		philos->must_eat++;
		philos->forks_cnt = 0;
		pthread_mutex_unlock(&philos->table->forks[cur].fork);
		pthread_mutex_unlock(&philos->table->forks[next].fork);
	}
}

void	start_eating_even(t_philos *philos, int cur, int next)
{

	if (pthread_mutex_lock(&philos->table->forks[cur].fork) == 0)
	{
		printf("%d has taken a fork.\n", cur + 1);
		philos->forks_cnt++;
	}
	if (pthread_mutex_lock(&philos->table->forks[next].fork) == 0)
	{
		printf("%d has taken a fork.\n", cur + 1);
		philos->forks_cnt++;
	}
	if (philos->forks_cnt == 2)
	{
		printf("%d is eating.\n", cur + 1);
		milliseconds(philos->table->time_to_eat);
		philos->must_eat++;
		philos->forks_cnt = 0;
		pthread_mutex_unlock(&philos->table->forks[cur].fork);
		pthread_mutex_unlock(&philos->table->forks[next].fork);
	}
}

void	start_eating(t_philos *philos, int cur, int next)
{
	if (philos->cur % 2 == 0)
		start_eating_even(philos, cur, next);
	else if (philos->cur % 2 == 1)
		start_eating_odd(philos, cur, next);
}

void	start_sleeping(t_philos *philos, int cur)
{
	printf("%d is sleeping.\n", cur + 1);
	milliseconds(philos->table->time_to_sleep);
}

void	start_thinking(int cur)
{
	printf("%d is thinking.\n", cur + 1);
	usleep(100);
}

int	philo_is_alive(void)
{
	return (1);
}