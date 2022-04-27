/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaluwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:11:27 by ccaluwe           #+#    #+#             */
/*   Updated: 2022/04/25 11:06:58 by ccaluwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort3(t_list *a)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	node1 = a;
	node2 = a->next;
	node3 = node2->next;
	if (node2->i < node1->i && node1->i < node3->i && node2->i < node3->i)
		sa(a);
	if (node1->i < node2->i && node1->i > node3->i && node2->i > node3->i)
		rra(&a);
	if (node1->i > node2->i && node1->i > node3->i && node2->i < node3->i)
		ra(&a);
	if (node1->i < node2->i && node1->i < node3->i && node2->i > node3->i)
	{
		rra(&a);
		sa(a);
	}
	if (node1->i > node2->i && node1->i > node3->i && node2->i > node3->i)
	{
		ra(&a);
		sa(a);
	}
}

void	ft_small_sort(t_list *a, int size)
{
	t_list	*node1;
	t_list	*node2;

	node1 = a;
	node2 = a->next;
	if (size == 2)
		return ;
	if (size == 3)
	{
		if (node1->i > node2->i)
		{
			sa(a);
			return ;
		}
		else
			return ;
	}
	if (size == 4)
	{
		ft_sort3(a);
	}
}

static void	min_top(t_list **a, int index, int i)
{
	int	rep;

	rep = index - 1;
	while (i < rep)
	{
		ra(a);
		i++;
	}
}

static void	min_bot(t_list **a, int index, int i, int len)
{
	int	rep;

	rep = len - index + 1;
	while (i < rep)
	{
		rra(a);
		i++;
	}
}

void	ft_medium_sort(t_list *a, t_list *b, int sizea)
{
	int	len;
	int	index;
	int	i;

	while (sizea > 4)
	{
		index = find_min_node(a);
		len = list_len(a);
		i = 0;
		if (index <= ((len / 2) + 1))
			min_top(&a, index, i);
		if (index > ((len / 2) + 1))
			min_bot(&a, index, i, len);
		pb(&a, &b);
		sizea--;
	}
	ft_sort3(a);
	while (b)
		pa(&b, &a);
}
