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

void ft_sort3(l_list *a)
{
    l_list *node1;
    l_list *node2;
    l_list *node3;
    
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

int    find_min_node(l_list *stack)
{
    int     min;
    l_list  *tmp;
    int     index;

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
            return(index);
        tmp = tmp->next;
    }
    return(0);
}

void ft_small_sort(l_list *a, int size)
{
    l_list  *node1 = a;
    l_list  *node2 = a->next;

    if (size == 2)
        return;
    if (size == 3)
    {
        if (node1->i > node2->i)
        {
            sa(a);
            return;
        }
        else
            return;
    }
    if (size == 4)
    {
        ft_sort3(a);
    }
}

int ft_average(l_list *list)
{
    int c;
    int sum;
    l_list  *tmp;

    c = 0;
    sum = 0;
    tmp = list;

    while (tmp->next)
    {
        sum += tmp->i;
        c++;
        tmp = tmp->next;
    }
    return(sum / c);
}

void ft_medium_sort(l_list *a, l_list *b, int sizea)
{
    int len;
    int index;
    int rep;
    int i;

    while (sizea > 4)
    {
        index = find_min_node(a);
        len = list_len(a);
        
        if (index <= ((len / 2) + 1))
        {
            rep = index - 1;
            i = 0;
            while (i < rep)
            {
                ra(&a);
                i++;
            }
            pb(&a, &b);
            sizea--;
        }
        if (index > ((len / 2) + 1))
        {
            rep = len - index + 1;
            i = 0;
            while (i < rep)
            {
                rra(&a);
                i++;
            }
            pb(&a, &b);
            sizea--;
        }
    }
    ft_sort3(a);
    while (b)
    {
        pa(&b, &a);
    }
}
