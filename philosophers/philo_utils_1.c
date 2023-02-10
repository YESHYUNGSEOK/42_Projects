/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungseok <hyungseok@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:01:15 by hyungseok         #+#    #+#             */
/*   Updated: 2023/02/10 22:14:32 by hyungseok        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

void	args_init(t_args *args, int ac, char **av)
{
	int	i;
	int	j;

	if (ac != 5 && ac != 6) //handle arguments numbers
		err_msg("error: invalid arguments");
	args->num_of_philos = ft_atoi(av[1]);
	args->time_to_die = ft_atoi(av[2]);
	args->time_to_eat = ft_atoi(av[3]);
	args->time_to_sleep = ft_atoi(av[4]);
	if (args->num_of_philos <= 0 || args->time_to_die <= 0 
		|| args->time_to_eat <= 0 || args->time_to_sleep <= 0)
		err_msg("error: invalid arguments");
	if (ac == 6)
	{
		args->must_eat = ft_atoi(av[5]);
		if (args->must_eat <= 0)
			err_msg("error: invalid arguments");
	} 
}

void	*thread_function(void *data)
{
	return (data);
}

void	philos_init(t_args *args, t_philos *philos)
{
	static int	i;

	philos = malloc(sizeof(t_philos) * args->num_of_philos);
	if (!philos)
		err_msg("error: memory allocation failure");
	while (i < args->num_of_philos)
	{
		philos[i].id = pthread_create(&philos[i].philo, NULL, thread_function, NULL);	
		if (philos[i].id < 0)
			err_msg("error: thread creation failure");
	}
}