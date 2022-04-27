/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackB_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaluwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:52:17 by ccaluwe           #+#    #+#             */
/*   Updated: 2022/04/04 16:00:35 by ccaluwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_list *a)
{
	int		store;
	t_list	*next;

	next = a->next;
	store = a->i;
	a->i = next->i;
	next->i = store;
	write(1, "sb\n", 3);
}

void	set_tob(t_list *to, t_list *tmp, t_list **b)
{
	if (!to)
	{
		to = tmp;
		to->next = NULL;
		to->prev = NULL;
		*b = to;
	}
	else
	{
		tmp->next = to;
		tmp->prev = NULL;
		to->prev = tmp;
		*b = tmp;
	}
}

void	pb(t_list **a, t_list **b)
{
	static t_list	*tmp;
	static t_list	*to;
	static t_list	*from;

	to = *b;
	from = *a;
	if (!from)
		return ;
	tmp = from;
	if (!(from->next))
		from = NULL;
	else
	{
		from = from->next;
		from->prev = NULL;
	}
	*a = from;
	set_tob(to, tmp, b);
	write(1, "pb\n", 3);
}

void	rb(t_list **a)
{
	t_list	*first;
	t_list	*last;
	t_list	*stack;

	stack = *a;
	if (!(stack && stack->next))
		return ;
	first = stack;
	stack = stack->next;
	last = stack;
	while (last->next)
	{
		last = last->next;
	}
	last->next = first;
	first->next = NULL;
	first->prev = last;
	stack->prev = NULL;
	*a = stack;
	write(1, "rb\n", 3);
}

void	rrb(t_list **a)
{
	t_list	*stack;
	t_list	*first;
	t_list	*last;

	first = *a;
	if (!(first && first->next))
		return ;
	stack = first;
	while (stack->next->next)
		stack = stack->next;
	last = stack;
	stack = stack->next;
	stack->prev = NULL;
	stack->next = first;
	first->prev = stack;
	last->next = NULL;
	*a = stack;
	write(1, "rrb\n", 4);
}
