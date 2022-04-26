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


//something breaks in free
/*static void  lst_free(l_list **list)
{
    l_list *swap;
    while (list && *list)
    {
        swap = (*list)->next;
        free(*list);
        *list = swap;
    }
}*/

l_list  *lst_newnode(char *integ)
{
    l_list *node;

    node = malloc(sizeof(l_list));
    if (!node)
        return(NULL);
    node->i = ft_check_atoi(integ);
    node->index = -1;
    node->next = NULL;
    node->prev = NULL;
    return (node);
}

int	list_len(l_list *stack)
{
	l_list *tmp;
    int len;

    tmp = stack;
    len = 0;
	 while (tmp)
	 {
		len++;
		tmp = tmp->next;
	 }
	 return(len);
}

/*static void  lst_addfront(l_list *node, l_list **list)
{
    if (list && node)
    {
        node->next = *list;
        node->prev = NULL;
        if (*list)
            (*list)->prev = node;
        *list = node;
    }
}*/

void  lst_addback(l_list *newNode, l_list **head)
{
    l_list *last = *head;
    if(*head == NULL)
    {
        newNode->prev=NULL;
        *head = newNode;
        return;
    }
    while(last->next)
    {
        last = last->next;
    }
    last->next = newNode;
    newNode->prev = last;
    return;
}

l_list  *ls_find_head(l_list *list)
{
    l_list  *head;

    head = list;
    while (head->prev)
    {
        head = head->prev;
    }
    return (head);
}
