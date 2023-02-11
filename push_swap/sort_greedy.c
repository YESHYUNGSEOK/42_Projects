/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_greedy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 21:03:16 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/01/03 17:06:31 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	before_push_all(t_deque *a, t_deque *b, int *cnt_a, int *cnt_b)
{
	int	cnt;

	if (*cnt_a < 0 && *cnt_b < 0)
	{
		if (*cnt_a < *cnt_b)
			cnt = absolute(*cnt_b) + 1;
		else
			cnt = absolute(*cnt_a) + 1;
		*cnt_a = *cnt_a + cnt - 1;
		*cnt_b = *cnt_b + cnt - 1;
		while (--cnt)
			rrr(a, b);
	}
	else if (*cnt_a > 0 && *cnt_b > 0)
	{
		if (*cnt_a < *cnt_b)
			cnt = *cnt_a;
		else
			cnt = *cnt_b;
		*cnt_a = *cnt_a - cnt;
		*cnt_b = *cnt_b - cnt;
		++cnt;
		while (--cnt)
			rr(a, b);
	}
}

static void	before_push_a(t_deque *a, int *cnt_a)
{
	if (*cnt_a > 0)
	{
		++*cnt_a;
		while (--*cnt_a)
			ra(a);
	}
	else if (*cnt_a < 0)
	{
		*cnt_a = absolute(*cnt_a);
		++*cnt_a;
		while (--*cnt_a)
			rra(a);
	}
}

static void	before_push_b(t_deque *b, int *cnt_b)
{
	if (*cnt_b > 0)
	{
		++*cnt_b;
		while (--*cnt_b)
			rb(b);
	}
	else if (*cnt_b < 0)
	{
		*cnt_b = absolute(*cnt_b);
		++*cnt_b;
		while (--*cnt_b)
			rrb(b);
	}
}

void	sort_greedy(t_deque *a, t_deque *b)
{
	int	cnt_a;
	int	cnt_b;

	while (b->size)
	{
		find_best(a, b, &cnt_a, &cnt_b);
		before_push_all(a, b, &cnt_a, &cnt_b);
		before_push_a(a, &cnt_a);
		before_push_b(b, &cnt_b);
		pa(a, b);
	}
	final_sort(a, 0, 0);
}
