/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungseok <hyungseok@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:28:58 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/01/01 09:18:00 by hyungseok        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_deque *a)
{
	if (a->head->data == a->tail->data)
		return ;
	tail_in(a, a->head->data);
	head_out(a);
	write(1, "ra\n", 3);
}

void	rb(t_deque *b)
{
	if (b->head->data == b->tail->data)
		return ;
	tail_in(b, b->head->data);
	head_out(b);
	write(1, "rb\n", 3);
}

void	rr(t_deque *a, t_deque *b)
{
	if (a->head->data == a->tail->data)
		return ;
	tail_in(a, a->head->data);
	head_out(a);
	if (b->head->data == b->tail->data)
		return ;
	tail_in(b, b->head->data);
	head_out(b);
	write(1, "rr\n", 3);
}
