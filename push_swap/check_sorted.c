/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:31:32 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/01/03 17:34:42 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_deque *a)
{
	t_deque	tmp;
	int		min;

	tmp = *a;
	tmp.head = tmp.head->next;
	min = a->head->data;
	while (tmp.head)
	{
		if (min > tmp.head->data)
			return (1);
		min = tmp.head->data;
		tmp.head = tmp.head->next;
	}
	return (0);
}
