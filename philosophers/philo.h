/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungseok <hyungseok@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:39:39 by hyungseok         #+#    #+#             */
/*   Updated: 2023/02/10 21:39:09 by hyungseok        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_args
{
	int	num_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat;
}	t_args;

typedef struct s_philos
{
	pthread_t	philo;
	int			id;
}	t_philos;

void	err_msg(char *str);
void	args_init(t_args *args, int ac, char **av);
void	philos_init(t_args *args, t_philos *philos);
void	*thread_function(void *data);

//libft
int		ft_atoi(const char *str);

#endif