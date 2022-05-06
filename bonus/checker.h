/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaluwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:34:27 by ccaluwe           #+#    #+#             */
/*   Updated: 2022/05/05 10:34:30 by ccaluwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int				i;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

int		ex_com(char *line, t_list **a, t_list **b);
int		ft_check_sort(t_list *list);
t_list	*create_list(char **argv, t_list *stack_a, int i);
t_list	*ft_parse(int argc, char **argv);
size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
int		count_words(const char *str, char c);
char	*get_next_line(int fd);
void	lst_free(t_list **list);
t_list	*lst_newnode(char *integ, t_list **stack);
int		list_len(t_list *stack);
void	lst_addback(t_list *newNode, t_list **head);
int		find_min_node(t_list *stack);
void	ft_check_dupli(char **str);
char	*ft_strdup(const char *s1);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_check_atoi(char *str);
void	ft_check_int(int n, unsigned long long int res);
int		ft_check_atoi_l(char *str, t_list *node, t_list **stack);
void	ss(t_list *stack_a, t_list *stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	sa(t_list *a);
void	pa(t_list **b, t_list **a);
void	ra(t_list **a);
void	rra(t_list **a);
void	sb(t_list *a);
void	pb(t_list **a, t_list **b);
void	rb(t_list **a);
void	rrb(t_list **a);
void	terminate(t_list *a, t_list *b);
void	execute_op(t_list **stack_a, t_list **stack_b, char *to_do);
char	**get_ops(void);
int		checker(t_list *a, t_list *b);
void	execute(t_list *stack_a, t_list *stack_b, char **ops);
char	*ft_strcat(char *dest, char *src);
t_list	*ft_parse(int argc, char **argv);
void	*ft_realloc(void *ptr, size_t new_size);
char	*ft_strcpy(char *dest, char *src);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		error_exit(void);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);

#endif
