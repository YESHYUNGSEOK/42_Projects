/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:00:57 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/01/03 19:41:16 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_loc_a(t_deque p, int find, int cnt, int guard)
{
	while (p.head)
	{
		if (p.head->prev == NULL && p.head->data > find
			&& p.tail->data < find)
			break ;
		if (guard > 0 && p.head->prev != NULL && p.head->prev->data > find
			&& p.head->data > find && p.head->prev->data > p.head->data)
			break ;
		if (guard > 0 && p.head->prev != NULL && p.head->prev->data < find
			&& p.head->data > find && p.head->prev->data < p.head->data)
			break ;
		if (guard > 0 && p.head->prev != NULL && p.head->prev->data < find
			&& p.head->data < find && p.head->prev->data > p.head->data)
			break ;
		guard++;
		cnt++;
		p.head = p.head->next;
	}
	if (cnt > p.size / 2)
		cnt = cnt - p.size;
	return (cnt);
}

void	find_best(t_deque *a, t_deque *b, int *cnt_a, int *cnt_b)
{
	int		cnt;
	int		loc_a;
	int		loc_b;
	int		best;
	t_deque	tmp;

	cnt = 0;
	best = 2147483647;
	tmp = *b;
	while (tmp.head)
	{
		loc_a = find_loc_a(*a, tmp.head->data, 0, 0);
		if (cnt > b->size / 2)
			loc_b = cnt - b->size;
		else
			loc_b = cnt;
		if (absolute(loc_a) + absolute(loc_b) <= best)
		{
			best = absolute(loc_a) + absolute(loc_b);
			*cnt_a = loc_a;
			*cnt_b = loc_b;
		}
		cnt++;
		tmp.head = tmp.head->next;
	}
}
