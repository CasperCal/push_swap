/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaluwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:34:13 by ccaluwe           #+#    #+#             */
/*   Updated: 2022/05/05 10:34:18 by ccaluwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

t_list	*create_list(char **argv, t_list *stack_a, int i)
{
	t_list	*node;

	while (argv[i])
	{
		node = lst_newnode(argv[i++], &stack_a);
		if (!node)
		{
			lst_free(&stack_a);
			exit(1);
		}
		lst_addback(node, &stack_a);
	}
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = ft_parse(argc, argv);
	stack_b = NULL;
	execute(stack_a, stack_b, get_ops());
	return (1);
}
