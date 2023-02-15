/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungseok <hyungseok@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:58:17 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/02/15 18:35:20 by hyungseok        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_eating(t_philos *philos, int cur, int next, int odd_even)
{
	while (philos->status == WAITING)
	{
		if (odd_even == 1)
		{
			first_fork(philos, cur);
			second_fork(philos, cur, next);
		}
		else if (odd_even == 0)
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
	pthread_mutex_lock(&philos->table->print);
	if (philos->table->philo_status != DEAD)
		printf("%dms\t%d\tis sleeping\n", \
		get_time() - philos->table->start_time, cur + 1);
	pthread_mutex_unlock(&philos->table->print);
	while (get_time() - sleep_start_time < philos->table->time_to_sleep)
		usleep(100);
	philos->status = SLEEPING;
}

void	start_thinking(t_philos *philos, int cur)
{
	if (check_status(philos))
		return ;
	pthread_mutex_lock(&philos->table->print);
	if (philos->table->philo_status != DEAD)
		printf("%dms\t%d\tis thinking\n", \
		get_time() - philos->table->start_time, cur + 1);
	pthread_mutex_unlock(&philos->table->print);
	philos->status = WAITING;
	usleep(50);
}
