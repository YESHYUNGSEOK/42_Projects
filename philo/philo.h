/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:14:26 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/02/11 17:23:22 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

enum	e_philo_status
{
	WAITING,
	EATING,
	SLEEPING,
	THINKING,
};

enum	e_fork_status
{
	UNUSED,
	USED,
	READY_TO_EAT,
};

typedef struct s_philos
{
	pthread_t	philo;
	int			status;
	int			fork_cnt;
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
	int				id;
	struct s_philos	*philos;
	struct s_forks	*forks;
}	t_table;

void	err_msg(char *str);
void	args_init(t_table *table, int ac, char **av);
void	table_init(t_table *table);
void	congression(t_table *table);
void	start_eating(t_table *table, int cur, int next);
void	start_sleeping(t_table *table, int cur);
void	start_thinking(t_table *table, int cur);
int		philo_is_alive(void);
//philo_utils
void	set_id(t_table *table, int *cur, int *next);

//utils
int		ft_atoi(const char *str);

#endif