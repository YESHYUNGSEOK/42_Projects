/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 05:55:51 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/01/03 17:45:13 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	mergesort_merge(int *arr, int left, int mid, int right)
{
	int	tmp[500];
	int	i;
	int	j;
	int	k;

	i = left;
	j = mid + 1;
	k = left;
	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
			tmp[k++] = arr[i++];
		else
			tmp[k++] = arr[j++];
	}
	while (i <= mid)
		tmp[k++] = arr[i++];
	while (j <= right)
		tmp[k++] = arr[j++];
	while (left <= right)
	{
		arr[left] = tmp[left];
		left++;
	}
}

static void	merge_sort(int *arr, int left, int right)
{
	int	mid;

	if (left < right)
	{
		mid = (left + right) / 2;
		merge_sort(arr, left, mid);
		merge_sort(arr, mid + 1, right);
		mergesort_merge(arr, left, mid, right);
	}
}

static void	get_pivot(t_deque *a, int ac, int *pivot1, int *pivot2)
{
	int		*arr;
	int		i;
	t_deque	tmp;

	arr = malloc(sizeof(int) * (ac - 1));
	tmp = *a;
	i = -1;
	while (tmp.head)
	{
		arr[++i] = tmp.head->data;
		tmp.head = tmp.head->next;
	}
	merge_sort(arr, 0, ac - 2);
	*pivot1 = arr[(ac - 1) / 3 * 2];
	*pivot2 = arr[(ac - 1) / 3];
	free(arr);
}

static int	is_sorted(t_deque *a)
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

void	divide_three(t_deque *a, t_deque *b, int ac)
{
	int		pivot1;
	int		pivot2;

	get_pivot(a, ac, &pivot1, &pivot2);
	while (--ac && is_sorted(a))
	{
		if (a->head->data <= pivot1)
		{
			pb(a, b);
			if (b->head->data <= pivot2)
				rb(b);
		}
		else
			ra(a);
	}
	while (a->size >= 3 && is_sorted(a))
		pb(a, b);
}
