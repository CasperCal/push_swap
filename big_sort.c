/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaluwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:24:57 by ccaluwe           #+#    #+#             */
/*   Updated: 2022/04/27 10:25:00 by ccaluwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
	{
		c++;
	}
	return (c);
}

static void	sort_array(int *array, int n)
{
	int		i;
	int		j;
	int		temp;

	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	ft_big_sort(t_list **stack_a, t_list **stack_b, int *sorted, int size_a)
{
	sort_array(sorted, size_a - 1);
	add_index(stack_a, sorted);
	ft_radix_sort(stack_a, stack_b);
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
