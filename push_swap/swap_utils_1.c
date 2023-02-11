/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:26:04 by hyungnoh          #+#    #+#             */
/*   Updated: 2022/12/19 17:28:25 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_deque *a)
{
	int	tmp;

	if (a->head->data == a->tail->data)
		return ;
	tmp = a->head->data;
	a->head->data = a->head->next->data;
	a->head->next->data = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_deque *b)
{
	int	tmp;

	if (b->head->data == b->tail->data)
		return ;
	tmp = b->head->data;
	b->head->data = b->head->next->data;
	b->head->next->data = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_deque *a, t_deque *b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}

void	pa(t_deque *a, t_deque *b)
{
	if (b->head == NULL)
		return ;
	head_in(a, head_out(b));
	write(1, "pa\n", 3);
}

void	pb(t_deque *a, t_deque *b)
{
	if (a->head == NULL)
		return ;
	head_in(b, head_out(a));
	write(1, "pb\n", 3);
}
