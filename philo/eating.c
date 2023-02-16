/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:26:29 by hyungseok         #+#    #+#             */
/*   Updated: 2023/02/16 12:20:53 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	meal(t_philos *philos, int cur, int next)
{
	if (check_status(philos))
		return ;
	pthread_mutex_lock(&philos->table->print);
	if (philos->table->philo_status != DEAD)
		printf("%d\t%d\tis eating\n", \
		get_time() - philos->table->start_time, cur + 1);
	pthread_mutex_unlock(&philos->table->print);
	philos->last_meal = get_time();
	while (get_time() < (philos->table->time_to_eat + philos->last_meal))
		usleep(philos->table->time_to_eat);
	philos->must_eat++;
	pthread_mutex_lock(&philos->table->forks[cur].fork);
	philos->table->forks[cur].status = IDLE;
	pthread_mutex_unlock(&philos->table->forks[cur].fork);
	pthread_mutex_lock(&philos->table->forks[next].fork);
	philos->table->forks[next].status = IDLE;
	pthread_mutex_unlock(&philos->table->forks[next].fork);
	philos->status = EATING;
}

void	first_fork(t_philos *philos, int cur)
{
	while (FORK_BEING_USED)
	{
		if (check_status(philos))
			return ;
		pthread_mutex_lock(&philos->table->forks[cur].fork);
		if (philos->table->forks[cur].status == IDLE)
		{
			pthread_mutex_lock(&philos->table->print);
			if (philos->table->philo_status != DEAD)
				printf("%d\t%d\thas taken a fork\n", \
				get_time() - philos->table->start_time, cur + 1);
			pthread_mutex_unlock(&philos->table->print);
			philos->table->forks[cur].status = USING;
			pthread_mutex_unlock(&philos->table->forks[cur].fork);
			break ;
		}
		else
			pthread_mutex_unlock(&philos->table->forks[cur].fork);
		usleep(50);
	}
}

void	second_fork(t_philos *philos, int cur, int next)
{
	while (FORK_BEING_USED)
	{
		if (check_status(philos))
			return ;
		pthread_mutex_lock(&philos->table->forks[next].fork);
		if (philos->table->forks[next].status == IDLE)
		{
			pthread_mutex_lock(&philos->table->print);
			if (philos->table->philo_status != DEAD)
				printf("%d\t%d\thas taken a fork\n", \
				get_time() - philos->table->start_time, cur + 1);
			pthread_mutex_unlock(&philos->table->print);
			philos->table->forks[next].status = USING;
			pthread_mutex_unlock(&philos->table->forks[next].fork);
			break ;
		}
		else
			pthread_mutex_unlock(&philos->table->forks[next].fork);
		usleep(50);
	}
}
