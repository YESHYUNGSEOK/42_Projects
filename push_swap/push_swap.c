/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:32:03 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/01/03 17:45:45 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_a(t_deque *deque, int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
		tail_in(deque, ft_atoi(av[i]));
}

int	main(int ac, char **av)
{
	t_deque	a;
	t_deque	b;

	check_av(ac, av);
	if (ac > 2)
	{
		deque_init(&a, &b);
		fill_a(&a, ac, av);
		sort(&a, &b, ac);
	}
	else
		exit(1);
	return (0);
}
