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

#include "push_swap.h"


void	sa(l_list *a)
{
		int 	store;
		l_list 	*next;

		next = a->next;
		store = a->i;
		a->i = next->i;
		next->i = store;
		write(1, "sa\n", 3);
}

void	pa(l_list **b, l_list **a)
{
    static l_list  *tmp;
    static l_list  *to;
    static l_list  *from;

    to = *a;
    from = *b;
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
    *b = from;
    if(!to)
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
	write(1, "pa\n", 3);
}

void ra(l_list **a)
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
	write(1, "ra\n", 3);
}

void rra(l_list **a)
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
    write(1,"rra\n", 4);
}