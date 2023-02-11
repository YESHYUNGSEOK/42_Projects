/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:30:25 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/01/03 17:35:58 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_deque
{
	int		size;
	t_node	*head;
	t_node	*tail;
}	t_deque;

void	deque_init(t_deque *a, t_deque *b);
void	head_in(t_deque *deque, int num);
void	tail_in(t_deque *deque, int num);
int		head_out(t_deque *deque);
int		tail_out(t_deque *deque);
void	sa(t_deque *a);
void	sb(t_deque *b);
void	ss(t_deque *a, t_deque *b);
void	pa(t_deque *a, t_deque *b);
void	pb(t_deque *a, t_deque *b);
void	ra(t_deque *a);
void	rb(t_deque *b);
void	rr(t_deque *a, t_deque *b);
void	rra(t_deque *a);
void	rrb(t_deque *b);
void	rrr(t_deque *a, t_deque *b);
void	sort(t_deque *a, t_deque *b, int ac);
int		check_sorted(t_deque *a);
void	divide_three(t_deque *a, t_deque *b, int ac);
void	sort_greedy(t_deque *a, t_deque *b);
void	find_best(t_deque *a, t_deque *b, int *cnt_a, int *cnt_b);
void	final_sort(t_deque *a, int min, int cnt);
ssize_t	ft_atoi(const char *str);
int		absolute(int n);
void	check_av(int ac, char **av);

#endif