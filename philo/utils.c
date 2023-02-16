/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:22:17 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/02/16 13:39:34 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	cnt_num(const char *str, int i)
{
	ssize_t	num;

	num = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (num > INT32_MAX || num < INT32_MIN)
		return (0);
	return ((int)num);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (str[i] && (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == ' ' || str[i] == '\v'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{	
		if (str[i] == '-')
			flag *= -1;
		i++;
	}
	return (cnt_num(str, i) * flag);
}

void	free_all(t_table *table, t_philos *philos)
{
	free(table->forks);
	free(table);
	free(philos);
}
