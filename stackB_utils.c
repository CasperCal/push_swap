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

void	sb(l_list *a)
{
		int 	store;
		l_list 	*next;

		next = a->next;
		store = a->i;
		a->i = next->i;
		next->i = store;
		write(1, "sb\n", 3);
}

void	pb(l_list **a, l_list **b)
{
    static l_list  *tmp;
    static l_list  *to;
    static l_list  *from;

    to = *b;
    from = *a;
    if(!from)
        return;
    tmp = from;
    if (!(from->next))
        from = NULL;
    else
    {
        from = from->next;
        from->prev = NULL;
    }
    *a = from;
    if(!to)
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
	write(1, "pb\n", 3);
}

void rb(l_list **a)
{
	l_list  *first;
    l_list  *last;
    l_list  *stack;

    stack = *a;
    if(!(stack && stack->next))
        return;
    first = stack;
    stack = stack->next;
    last = stack;
    while(last->next)
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

void rrb(l_list **a)
{
	l_list 	*stack;
    l_list  *first;
    l_list  *last;

    first = *a;
    if(!(first && first->next))
        return;
    stack = first;
    while(stack->next->next)
        stack = stack->next;
    last = stack;
    stack = stack->next;
    stack->prev = NULL;
    stack->next = first;
    first->prev = stack;
    last->next = NULL;
    *a = stack;
    write(1,"rrb\n", 4);
}