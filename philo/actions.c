/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:58:17 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/02/11 18:55:32 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_eating(t_table *table, int cur, int next)
{
	if (table->forks[cur].status == UNUSED)
	{
		pthread_mutex_lock(&table->forks[cur].fork);
		printf("philo_%d has taken a fork.\n", cur + 1);
		table->forks[cur].status = USED;
		table->philos[cur].fork_cnt++;
	}
	if (table->forks[next].status == UNUSED)
	{
		pthread_mutex_lock(&table->forks[next].fork);
		printf("philo_%d has taken a fork.\n", cur + 1);
		table->forks[next].status = USED;
		table->philos[cur].fork_cnt++;
	}
	if (table->philos[cur].fork_cnt == READY_TO_EAT)
	{
		printf("philo_%d is eating.\n", cur + 1);
		pthread_mutex_unlock(&table->forks[cur].fork);
		pthread_mutex_unlock(&table->forks[next].fork);
		table->philos[cur].status = EATING;
		table->forks[cur].status = UNUSED;
		table->forks[next].status = UNUSED;
		table->philos[cur].fork_cnt = 0;
		usleep(table->time_to_eat);
	}
}

void	start_sleeping(t_table *table, int cur)
{
	printf("philo_%d is sleeping.\n", cur + 1);
	table->philos[cur].status = SLEEPING;
	usleep(table->time_to_sleep);
}

void	start_thinking(t_table *table, int cur)
{
	printf("philo_%d is thinking.\n", cur + 1);
	table->philos[cur].status = WAITING;
	usleep(1);
}

int	philo_is_alive(void)
{
	return (1);
}