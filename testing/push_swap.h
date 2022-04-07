/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaluwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:15:00 by ccaluwe           #+#    #+#             */
/*   Updated: 2022/04/04 15:22:39 by ccaluwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

typedef struct	s_list
{
	int	i;
	struct s_list	*next;
	struct s_list	*prev;
}	l_list;

/*// Input parsing/ verification
int		ft_check_atoi(char *str);
int		ft_check_dupli(char **str);
int		ft_arrlen(int *arr);
int 	ft_check_sort(int *a, int size);

//Manipulating stack
void  	ss(int *a, int *b);
void 	rr(int *a, int *b);
void 	rrr(int *a, int *b);
void	sa(int *a);
void	pa(int *a, int *b);
void 	ra(int *a);
void 	rra(int *a);
void	sb(int *b);
void	pb(int *b, int *a);
void    rb(int *b);
void 	rrb(int *b);

// Sorting algorithm (quick sort inspired)
int ft_average(int *arr);
void ft_small_sort(int *a, int size);
void ft_sort3(int *a);
void ft_medium_sort(int *a);
void ft_big_sort(int *stack_a);
*/
#endif
