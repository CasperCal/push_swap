#include "push_swap.h"

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

void ft_big_sort(l_list **stack_a, l_list **stack_b, int *sorted, int size_a)
{
    sort_array(sorted, size_a - 1);
    add_index(stack_a, sorted);
    ft_radix_sort(stack_a, stack_b);
}