/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungseok <hyungseok@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:21:11 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/01/01 09:18:33 by hyungseok        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_deque *a)
{
	if (a->head->data == a->tail->data)
		return ;
	head_in(a, a->tail->data);
	tail_out(a);
	write(1, "rra\n", 4);
}

void	rrb(t_deque *b)
{
	if (b->head->data == b->tail->data)
		return ;
	head_in(b, b->tail->data);
	tail_out(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_deque *a, t_deque *b)
{
	if (a->head->data == a->tail->data)
		return ;
	head_in(a, a->tail->data);
	tail_out(a);
	if (b->head->data == b->tail->data)
		return ;
	head_in(b, b->tail->data);
	tail_out(b);
	write(1, "rrr\n", 4);
}
