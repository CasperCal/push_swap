/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackA_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaluwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:58:34 by ccaluwe           #+#    #+#             */
/*   Updated: 2022/04/04 15:52:32 by ccaluwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_list *a)
{
	int		store;
	t_list	*next;

	if (a && a->next)
	{
		next = a->next;
		store = a->i;
		a->i = next->i;
		next->i = store;
	}
}

void	set_toa(t_list *to, t_list *tmp, t_list **a)
{
	if (!to)
	{
		to = tmp;
		to->next = NULL;
		to->prev = NULL;
		*a = to;
	}
	else
	{
		tmp->next = to;
		tmp->prev = NULL;
		to->prev = tmp;
		*a = tmp;
	}
}

void	pa(t_list **b, t_list **a)
{
	static t_list	*tmp;
	static t_list	*to;
	static t_list	*from;

	to = *a;
	from = *b;
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
	*b = from;
	set_toa(to, tmp, a);
}

void	ra(t_list **a)
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
}

void	rra(t_list **a)
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
}
