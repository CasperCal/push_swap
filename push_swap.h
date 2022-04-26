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
#include <stdio.h>
#include <stdbool.h>

typedef struct	s_list
{
	int	i;
	int index;
	struct s_list	*next;
	struct s_list	*prev;
}	l_list;

// Input parsing/ verification
int		ft_check_atoi(char *str);
void		ft_check_dupli(char **str);
int		count_words(const char *str, char c);
char	**ft_split(char const *s, char c);
int ft_check_sort(l_list *list);
void    print_list(l_list *stack, char stackname);
l_list	*ft_parse(int argc, char **argv);
size_t	ft_strlen(const char *str);

//l_list toolbox
//static void  lst_free(l_list **list);
l_list  *lst_newnode(char *integ);
//static void  lst_addfront(l_list *node, l_list **list);
void  lst_addback(l_list *newNode, l_list **head);
l_list  *ls_find_head(l_list *list);

//Manipulating stack
void	sa(l_list *a);
void	pa(l_list **b, l_list **a);
void 	ra(l_list **a);
void rra(l_list **a);
void	sb(l_list *a);
void	pb(l_list **a, l_list **b);
void rb(l_list **a);
void rrb(l_list **a);
void  ss(l_list *a, l_list *b);
void rr(l_list *a, l_list *b);
void rrr(l_list *a, l_list *b);

//Indexification
int	*store_array(int argc, char **argv);
void add_index(l_list **stack_a, int *sorted);

// Sorting algorithm (quick sort inspired)
int ft_average(l_list *list);
void ft_small_sort(l_list *a, int size);
void ft_sort3(l_list *a);
void ft_medium_sort(l_list *a, l_list *b, int sizea);
int    find_min_node(l_list *stack);
int     list_len(l_list *stack);
void ft_radix_sort(l_list **stack_a, l_list **stack_b);
void ft_big_sort(l_list **stack_a, l_list **stack_b, int *sorted, int size_a);


#endif
