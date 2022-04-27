/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaluwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:24:41 by ccaluwe           #+#    #+#             */
/*   Updated: 2022/04/25 12:49:17 by ccaluwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_free(t_list **list)
{
	t_list	*node;

	node = *list;
	while (node)
	{
		node = (*list)->next;
		free(*list);
		*list = node;
	}
}

t_list	*lst_newnode(char *integ)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->i = ft_check_atoi(integ);
	node->index = -1;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

int	list_len(t_list *stack)
{
	t_list	*tmp;
	int		len;

	tmp = stack;
	len = 0;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

void	lst_addback(t_list *newNode, t_list **head)
{
	t_list	*last;

	last = *head;
	if (*head == NULL)
	{
		newNode->prev = NULL;
		*head = newNode;
		return ;
	}
	while (last->next)
	{
		last = last->next;
	}
	last->next = newNode;
	newNode->prev = last;
	return ;
}

int	find_min_node(t_list *stack)
{
	int		min;
	t_list	*tmp;
	int		index;

	min = INT_MAX;
	index = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->i < min)
			min = tmp->i;
		tmp = tmp->next;
	}
	tmp = stack;
	while (tmp)
	{
		index++;
		if (tmp->i == min)
			return (index);
		tmp = tmp->next;
	}
	return (0);
}
