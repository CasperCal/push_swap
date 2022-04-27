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

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

//stack structure
typedef struct s_list
{
	int				i;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

// Input parsing/ verification
int		ft_check_atoi(char *str);
void	ft_check_dupli(char **str);
int		count_words(const char *str, char c);
char	**ft_split(char const *s, char c);
int		ft_check_sort(t_list *list);
void	print_list(t_list *stack, char stackname);
t_list	*ft_parse(int argc, char **argv);
size_t	ft_strlen(const char *str);

//t_list toolbox
void	lst_free(t_list **list);
t_list	*lst_newnode(char *integ);
void	lst_addback(t_list *newNode, t_list **head);
int		list_len(t_list *stack);
int		find_min_node(t_list *stack);

//Manipulating stack
void	sa(t_list *a);
void	pa(t_list **b, t_list **a);
void	ra(t_list **a);
void	rra(t_list **a);
void	sb(t_list *a);
void	pb(t_list **a, t_list **b);
void	rb(t_list **a);
void	rrb(t_list **a);

//Indexification
int		*store_array(int argc, char **argv);
void	add_index(t_list **stack_a, int *sorted);

// Sorting algorithm
int		ft_average(t_list *list);
void	ft_small_sort(t_list *a, int size);
void	ft_sort3(t_list *a);
void	ft_medium_sort(t_list *a, t_list *b, int sizea);
void	ft_radix_sort(t_list **stack_a, t_list **stack_b);
void	ft_big_sort(t_list **stack_a, t_list **stack_b, \
						int *sorted, int size_a);

#endif
