/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaluwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:42:21 by ccaluwe           #+#    #+#             */
/*   Updated: 2022/05/05 14:42:36 by ccaluwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

#include "checker.h"

void	terminate(t_list *a, t_list *b)
{
	if (checker(a, b))
	{
		lst_free(&a);
		write(1, "OK\n", 3);
		exit(0);
	}
	lst_free(&a);
	if (b)
		lst_free(&b);
	write(1, "KO\n", 3);
	system("leaks checker");
	exit(1);
}

void	execute_op(t_list **stack_a, t_list **stack_b, char *to_do)
{
	if (!ft_strcmp(to_do, "sa"))
		sa(*stack_a);
	else if (!ft_strcmp(to_do, "sb"))
		sb(*stack_b);
	else if (!ft_strcmp(to_do, "ss"))
		ss(*stack_a, *stack_b);
	else if (!ft_strcmp(to_do, "ra"))
		ra(stack_a);
	else if (!ft_strcmp(to_do, "rb"))
		rb(stack_b);
	else if (!ft_strcmp(to_do, "rr"))
		rr(stack_a, stack_b);
	else if (!ft_strcmp(to_do, "rra"))
		rra(stack_a);
	else if (!ft_strcmp(to_do, "rrb"))
		rrb(stack_b);
	else if (!ft_strcmp(to_do, "rrr"))
		rrr(stack_a, stack_b);
	else if (!ft_strcmp(to_do, "pa"))
		pa(stack_b, stack_a);
	else if (!ft_strcmp(to_do, "pb"))
		pb(stack_a, stack_b);
	else
		error_exit();
}

char	**get_ops(void)
{
	char	*res;
	char	*r_data;

	res = NULL;
	r_data = get_next_line(0);
	while (r_data)
	{
		res = ft_strcat(res, r_data);
		free(r_data);
		r_data = get_next_line(0);
	}
	return (ft_split(res, '\n'));
}

int	checker(t_list *a, t_list *b)
{
	if (b)
		return (0);
	while (a && a->next)
	{
		if (a->i > a->next->i)
			return (0);
		a = a->next;
	}
	return (1);
}

void	execute(t_list *stack_a, t_list *stack_b, char **ops)
{
	int		i;

	if (!ops)
		terminate(stack_a, stack_b);
	i = -1;
	while (ops[++i])
	{
		execute_op(&stack_a, &stack_b, ops[i]);
	}
	terminate(stack_a, stack_b);
}
