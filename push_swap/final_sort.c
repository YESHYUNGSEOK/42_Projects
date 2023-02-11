/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 17:39:44 by hyungseok         #+#    #+#             */
/*   Updated: 2023/01/03 17:05:54 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min(t_deque *a)
{
	t_deque	tmp;
	int		min;

	tmp = *a;
	min = a->head->data;
	while (tmp.head)
	{
		if (tmp.head->data < min)
			min = tmp.head->data;
		tmp.head = tmp.head->next;
	}
	return (min);
}

void	final_sort(t_deque *a, int min, int cnt)
{
	t_deque	tmp;

	tmp = *a;
	min = get_min(a);
	cnt = 0;
	while (tmp.head)
	{
		if (tmp.head->data == min)
			break ;
		cnt++;
		tmp.head = tmp.head->next;
	}
	if (cnt > a->size / 2)
	{
		while (a->head->data != min)
			rra(a);
	}
	else
	{
		while (a->head->data != min)
			ra(a);
	}
}
