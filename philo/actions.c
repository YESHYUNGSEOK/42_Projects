/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:58:17 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/02/16 12:19:40 by hyungnoh         ###   ########.fr       */
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
	pthread_mutex_lock(&philos->table->print);
	if (philos->table->philo_status != DEAD)
		printf("%d\t%d\tis sleeping\n", \
		get_time() - philos->table->start_time, cur + 1);
	pthread_mutex_unlock(&philos->table->print);
	sleep_start_time = get_time();
	while (get_time() < philos->table->time_to_sleep + sleep_start_time)
		usleep(100);
	philos->status = SLEEPING;
}

void	start_thinking(t_philos *philos, int cur)
{
	if (check_status(philos))
		return ;
	pthread_mutex_lock(&philos->table->print);
	if (philos->table->philo_status != DEAD)
		printf("%d\t%d\tis thinking\n", \
		get_time() - philos->table->start_time, cur + 1);
	pthread_mutex_unlock(&philos->table->print);
	philos->status = WAITING;
	usleep(100);
}
