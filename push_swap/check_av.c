/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:31:59 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/01/03 17:25:25 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	isnum(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	if ((str[i] == '-' || str[i] == '+') && str[i + 1] != '\0')
		i++;
	while (str[i])
	{
		if (!(str[i] >= 48 && str[i] <= 57))
			return (1);
		i++;
	}
	return (0);
}

static int	repeat_check(char *str, char **av, int idx)
{
	int	i;

	i = 0;
	while (++i < idx)
	{
		if (ft_atoi(str) == ft_atoi(av[i]))
			return (1);
	}
	return (0);
}

static int	isrepeat(char **av)
{
	int	i;

	i = 0;
	while (av[++i])
	{
		if (repeat_check(av[i], av, i))
			return (1);
	}
	return (0);
}

void	check_av(int ac, char **av)
{
	ssize_t	tmp;
	int		i;

	i = 0;
	while (++i < ac)
	{
		if (isnum(av[i]))
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		tmp = ft_atoi(av[i]);
		if (!(tmp >= INT_MIN && tmp <= INT_MAX))
		{
			write(1, "Error\n", 6);
			exit(1);
		}
	}
	if (isrepeat(av))
	{
		write(1, "Error\n", 6);
		exit(1);
	}
}
