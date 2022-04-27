/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaluwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:10:43 by ccaluwe           #+#    #+#             */
/*   Updated: 2022/04/25 12:39:44 by ccaluwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*str_to_arr(char **argv)
{
	int	i;
	int	len;
	int	*array;

	i = 0;
	len = (count_words(argv[1], ' '));
	argv = ft_split(argv[1], ' ');
	if (!argv)
		exit(1);
	array = malloc(sizeof(int) * len);
	if (!array)
		exit(1);
	while (i < len)
	{
		array[i] = ft_check_atoi(argv[i]);
		i++;
	}
	free(argv);
	return (array);
}

int	*store_array(int argc, char **argv)
{
	int	i;
	int	j;
	int	*array;

	i = 0;
	j = 1;
	array = malloc(sizeof(int) * (argc));
	if (!array)
		return (NULL);
	if (argc == 2)
	{
		array = str_to_arr(argv);
		return (array);
	}
	else
	{
		while (j < argc)
		{
			array[i] = ft_check_atoi(argv[j]);
			j++;
			i++;
		}
		return (array);
	}
}

void	add_index(t_list **stack_a, int *sorted)
{
	t_list	*node;
	int		i;

	node = *stack_a;
	while (node)
	{
		i = 0;
		while (node->index == -1)
		{
			if (sorted[i] == node->i)
			{
				node->index = i;
			}
			i++;
		}
		node = node->next;
	}
}

static int	ft_max_bits(t_list **stack)
{
	t_list	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	ft_radix_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = *stack_a;
	size = list_len(head_a);
	max_bits = ft_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *stack_a;
			if (((head_a->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (list_len(*stack_b) != 0)
			pa(stack_b, stack_a);
		i++;
	}
}
