/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungseok <hyungseok@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:58:17 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/02/15 12:33:06 by hyungseok        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	meal(t_philos *philos, int cur, int next)
{
	if (check_status(philos))
		return ;
	philos->last_meal = get_time();
	printf("%dms\t%d\tis eating\n", get_time() - philos->table->start_time, cur + 1);
	while (get_time() - philos->last_meal < philos->table->time_to_eat)
		usleep(100);
	philos->must_eat++;
	philos->table->forks[cur].status = IDLE;
	philos->table->forks[next].status = IDLE;
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
			printf("%dms\t%d\thas taken a fork\n", get_time() - philos->table->start_time, cur + 1);
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
		if (check_status(philos))
			return ;
		pthread_mutex_lock(&philos->table->forks[next].fork);
		if (philos->table->forks[next].status == IDLE)
		{
			printf("%dms\t%d\thas taken a fork\n", get_time() - philos->table->start_time, cur + 1);
			philos->table->forks[next].status = USING;
			pthread_mutex_unlock(&philos->table->forks[next].fork);
			break ;
		}
		else
			pthread_mutex_unlock(&philos->table->forks[next].fork);
	}
}

void	start_eating(t_philos *philos, int cur, int next, int odd_even)
{
	while (philos->status == WAITING)
	{
		if (odd_even == 0)
		{
			first_fork(philos, cur);
			second_fork(philos, cur, next);
		}
		else if (odd_even == 1)
		{
			second_fork(philos, cur, next);
			first_fork(philos, cur);
		}
		meal(philos, cur, next);
	}
}

void	start_sleeping(t_philos *philos, int cur)
{
	int	sleep_start_time;

	if (check_status(philos))
		return ;
	sleep_start_time = get_time();
	printf("%dms\t%d\tis sleeping\n", get_time() - philos->table->start_time, cur + 1);
	while (get_time() - sleep_start_time < philos->table->time_to_sleep)
		usleep(100);
	philos->status = SLEEPING;
}

void	start_thinking(t_philos *philos, int cur)
{
	if (check_status(philos))
		return ;
	printf("%dms\t%d\tis thinking\n", get_time() - philos->table->start_time, cur + 1);
	usleep(100);
	philos->status = WAITING;
}
