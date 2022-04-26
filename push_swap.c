/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaluwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:17:39 by ccaluwe           #+#    #+#             */
/*   Updated: 2022/04/25 12:44:38 by ccaluwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_check_sort(l_list *list)
{
    l_list *tmp;

    tmp = list;
    while (tmp->next)
    {
        if (tmp->i > tmp->next->i)
            return(0);
        tmp = tmp->next;
    }
    return(1);
}

void    print_list(l_list *stack, char stackname)
{
    if (!stack)
        printf("Node %c: Empty stack.", stackname);
    while (stack)
    {
        printf("Node %c: %i\n", stackname, stack->i);
        stack = stack->next;
    }
}

int main(int argc, char **argv)
{
    static l_list *stack_a;
    static l_list *stack_b;
	int			*sorted;

    sorted = store_array(argc, argv);
    stack_a = ft_parse(argc, argv);
    if (argc == 2)
        argc = (count_words(argv[1], ' ') + 1);
    stack_b = NULL;
    
    if (ft_check_sort(stack_a) == 1)
        return (1);
    if (argc <= 4)
    {
        ft_small_sort(stack_a, argc);
        return (1);
    }
    else if (argc <= 7)
    {
        ft_medium_sort(stack_a, stack_b, argc);
        return (1);
    }
    else
    {
        ft_big_sort(&stack_a, &stack_b, sorted, argc);
        return (1);
    }
}
