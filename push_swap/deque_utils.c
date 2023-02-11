/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:46:51 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/01/03 19:04:53 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	deque_init(t_deque *a, t_deque *b)
{
	a->size = 0;
	a->head = NULL;
	a->tail = NULL;
	b->size = 0;
	b->head = NULL;
	b->tail = NULL;
}

void	head_in(t_deque *deque, int num)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (deque->head == NULL)
	{
		node->data = num;
		node->prev = NULL;
		node->next = NULL;
		deque->head = node;
		deque->tail = node;
		deque->size++;
		return ;
	}
	node->data = num;
	deque->head->prev = node;
	node->next = deque->head;
	deque->head = node;
	node->prev = NULL;
	deque->size++;
}

void	tail_in(t_deque *deque, int num)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (deque->tail == NULL)
	{
		node->data = num;
		node->prev = NULL;
		node->next = NULL;
		deque->head = node;
		deque->tail = node;
		deque->size++;
		return ;
	}
	node->data = num;
	deque->tail->next = node;
	node->prev = deque->tail;
	deque->tail = node;
	node->next = NULL;
	deque->size++;
}

int	head_out(t_deque *deque)
{
	t_node	*node;
	int		num;

	num = deque->head->data;
	node = deque->head;
	deque->head = deque->head->next;
	free(node);
	deque->size--;
	return (num);
}

int	tail_out(t_deque *deque)
{
	t_node	*node;
	int		num;

	num = deque->tail->data;
	node = deque->tail;
	deque->tail = deque->tail->prev;
	deque->tail->next = NULL;
	free(node);
	deque->size--;
	return (num);
}
