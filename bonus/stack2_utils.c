/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaluwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:22:00 by ccaluwe           #+#    #+#             */
/*   Updated: 2022/05/05 13:22:19 by ccaluwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*z1;
	unsigned char	*z2;

	z1 = (unsigned char *)s1;
	z2 = (unsigned char *)s2;
	if (*z1 == '\0')
		return (-(*z2));
	if (*z2 == '\0')
		return (*z1);
	while (*z1 != '\0' || *z2 != '\0')
	{
		if (*z1 != *z2)
			return (*z1 - *z2);
		z1++;
		z2++;
	}
	return (0);
}

int	ft_check_atoi_l(char *str, t_list *node, t_list **stack)
{
	int					i;
	int					n;
	unsigned long long	res;

	i = 0;
	n = 1;
	res = 0;
	if (str[i] == '-')
	{
		n *= -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			write(1, "Error\n", 6);
			free(node);
			lst_free(stack);
			exit(1);
		}
		res = (res * 10) + (str[i++] - '0');
	}
	ft_check_int(n, res);
	return (res * n);
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
