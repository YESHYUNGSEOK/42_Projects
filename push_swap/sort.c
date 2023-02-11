/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:40:15 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/01/03 17:55:45 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_deque *a)
{
	if (a->head->data > a->tail->data)
		sa(a);
	return ;
}

static void	sort_three(t_deque *a)
{
	if (a->head->data < a->head->next->data
		&& a->head->next->data < a->tail->data)
		return ;
	if (a->head->data > a->head->next->data && a->head->data < a->tail->data)
		sa(a);
	else if (a->head->data > a->head->next->data
		&& a->head->data > a->tail->data)
	{
		if (a->head->next->data > a->tail->data)
		{
			sa(a);
			rra(a);
		}
		else
			ra(a);
	}
	else if (a->head->data < a->head->next->data
		&& a->head->data > a->tail->data)
		rra(a);
	else if (a->head->data < a->head->next->data
		&& a->head->data < a->tail->data)
	{
		sa(a);
		ra(a);
	}
}

void	sort(t_deque *a, t_deque *b, int ac)
{
	if (check_sorted(a))
	{
		if (ac == 3)
			sort_two(a);
		else if (ac == 4)
			sort_three(a);
		else if (ac == 6)
		{
			pb(a, b);
			pb(a, b);
			sort_three(a);
			sort_greedy(a, b);
		}
		else
		{
			divide_three(a, b, ac);
			if (a->size == 3)
				sort_three(a);
			else if (a->size == 2)
				sort_two(a);
			sort_greedy(a, b);
		}
	}
	else
		exit(1);
}
