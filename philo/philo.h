/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungseok <hyungseok@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:14:26 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/02/15 17:27:10 by hyungseok        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

# define TRUE 1
# define FALSE 0
# define FORK_BEING_USED 1

enum	e_philo_status
{
	WAITING,
	EATING,
	SLEEPING,
	FULL,
	ALIVE,
	DEAD,
};

enum	e_fork_status
{
	IDLE,
	USING,
};

typedef struct s_philos
{
	pthread_t		thread;
	int				cur;
	int				next;
	int				status;
	int				must_eat;
	int				last_meal;
	struct s_table	*table;
}	t_philos;

typedef struct s_forks
{
	pthread_mutex_t	fork;
	int				status;
}	t_forks;

typedef struct s_table
{
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				start_time;
	int				philo_status;
	pthread_mutex_t	die;
	pthread_mutex_t	print;
	struct s_forks	*forks;
}	t_table;

int		forks_init(t_table *table);
int		table_init(t_table *table, int ac, char **av);
int		philos_init(t_table *table, t_philos *philos);
int		congression(t_table *table, t_philos *philos);
void	start_eating(t_philos *philos, int cur, int next, int odd_even);
void	first_fork(t_philos *philos, int cur);
void	second_fork(t_philos *philos, int cur, int next);
void	meal(t_philos *philos, int cur, int next);
void	start_sleeping(t_philos *philos, int cur);
void	start_thinking(t_philos *philos, int cur);
int		philo_is_alive(t_philos *philos);
//philo_utils
void	set_fork_cursor(int	*left, int *right, int i, int num_of_philos);
int		philo_is_full(t_philos *philos);
int		check_status(t_philos *philos);
int		get_time(void);
void	free_all(t_table *table, t_philos *philos);
//utils
int		ft_atoi(const char *str);

#endif