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

int	ft_check_sort(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp->next)
	{
		if (tmp->i > tmp->next->i)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_list	*create_list(char **argv, t_list *stack_a, int i)
{
	t_list	*node;

	while (argv[i])
	{
		node = lst_newnode(argv[i++]);
		if (!node)
		{
			lst_free(&stack_a);
			exit(1);
		}
		lst_addback(node, &stack_a);
	}
	return (stack_a);
}

t_list	*ft_parse(int argc, char **argv)
{
	t_list	*stack_a;
	int		i;
	int		c;

	i = 1;
	c = 0;
	stack_a = NULL;
	if (argc <= 1)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			exit(1);
		i = 0;
	}
	ft_check_dupli(argv);
	stack_a = create_list(argv, stack_a, i);
	return (stack_a);
}

void	ft_pick_sort(t_list *stack_a, t_list *stack_b, int *sorted, int argc)
{
	if (argc <= 4)
	{
		ft_small_sort(stack_a, argc);
		free(sorted);
		lst_free(&stack_a);
		return ;
	}
	else if (argc <= 7)
	{
		ft_medium_sort(stack_a, stack_b, argc);
		free(sorted);
		lst_free(&stack_a);
		return ;
	}
	else
	{
		ft_big_sort(&stack_a, &stack_b, sorted, argc);
		free(sorted);
		lst_free(&stack_a);
		return ;
	}
}

int	main(int argc, char **argv)
{
	static t_list	*stack_a;
	static t_list	*stack_b;
	int				*sorted;

	sorted = store_array(argc, argv);
	stack_a = ft_parse(argc, argv);
	if (argc == 2)
		argc = (count_words(argv[1], ' ') + 1);
	stack_b = NULL;
	if (ft_check_sort(stack_a) == 1)
	{
		free(sorted);
		lst_free(&stack_a);
		return (1);
	}
	ft_pick_sort(stack_a, stack_b, sorted, argc);
	return (1);
}
