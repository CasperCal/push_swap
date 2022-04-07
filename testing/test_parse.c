#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include "push_swap.h"


static void  lst_free(l_list **list)
{
    l_list *swap;
    while (list && *list)
    {
        swap = (*list)->next;
        free(*list);
        *list = swap;
    }
}

int		ft_check_atoi(char *str)
{
	int	i;
	int n;
	unsigned long long res;

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
			write(1,"Error\n", 6);
			exit(1);
		}
		res = (res * 10) + (str[i++] - '0');
	}
	if (n == 1 && res > INT_MAX)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	if (n == -1 && res - 1 > INT_MAX)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	return(res * n);
}

l_list  *lst_newnode(char *integ)
{
    l_list *node;

    node = malloc(sizeof(l_list));
    if (!node)
        return(NULL);
    node->i = ft_check_atoi(integ);
    node->next = NULL;
    node->prev = NULL;
    return (node);
}


static void  lst_addfront(l_list *node, l_list **list)
{
    if (list && node)
    {
        node->next = *list;
        node->prev = NULL;
        if (*list)
            (*list)->prev = node;
        *list = node;
    }
}

static void  lst_addback(l_list *newNode, l_list **head)
{
    l_list *last = *head;
    if(*head == NULL)
    {
        newNode->prev=NULL;
        *head = newNode;
        return;
    }
    while(last->next)
    {
        last = last->next;
    }
    last->next = newNode;
    newNode->prev = last;
    return;
}

static int	count_words(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

int	ft_wordlen(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static char	*word_dup(const char *s, char c, char *split, int k)
{
	char	*word;
	int		i;
	int		j;

	i = 0;
	j = 0;
	word = malloc((ft_wordlen(&s[k], c) + 1) * sizeof(char));
	if (!word)
	{
		while (split[j])
		{
			free(&split[j]);
			j++;
		}
		free(split);
		return (NULL);
	}
	while (s[k] != c && s[k])
	{
		word[i++] = s[k++];
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**split;

	if (!s)
		return (NULL);
	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	split[0] = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			split[j++] = word_dup(s, c, *split, i);
			i += ft_wordlen(&s[i], c);
			split[j] = 0;
		}
		else
			i++;
	}
	return (split);
}

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

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] || s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
		{
			if (s1[i] > s2[i])
				return (1);
			else
				return (-1);
		}
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;
	int		size;

	size = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * (size + 1));
	if (!s2)
		return (0);
	i = 0;
	while (*((char *)s1 + i))
	{
		s2[i] = *((char *)s1 + i);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

void		ft_check_dupli(char **str)
{
	int i;
    int j;
    char *cmp;


    i = 0;
    while(str[i])
    {
        cmp = ft_strdup(str[i]);
        j = 0;
        while (str[j])
        {
            if (j == i)
                j++;
            else if (ft_strcmp(cmp, str[j]) == 0)
            {
                write(1, "Error\n", 6);
                exit (1);
            }
            else
                j++;
        }
        i++;
    }
}

l_list	*ft_parse(int argc, char **argv)
{
	l_list	*stack_a;
	l_list  *node;
	int i;
    int c;

    i = 1;
    c = 0;
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
	stack_a = NULL;
	while (argv[i])
	{
		node = lst_newnode(argv[i++]);
		lst_addback(node, &stack_a);
	}
	return(stack_a);
}

void	sa(l_list *a)
{
		int 	store;
		l_list 	*next;

		next = a->next;
		store = a->i;
		a->i = next->i;
		next->i = store;
		write(1, "sa\n", 3);
}

void	pb(l_list **a, l_list **b)
{
    static l_list  *tmp;
    static l_list  *to;
    static l_list  *from;

    to = *b;
    from = *a;
    if(!from)
        return;
    tmp = from;
    if (!(from->next))
        from = NULL;
    else
    {
        from = from->next;
        from->prev = NULL;
    }
    *a = from;
    if(!to)
    {
        to = tmp;
        to->next = NULL;
        to->prev = NULL;
        *b = to;
    }
    else
    {
        tmp->next = to;
        tmp->prev = NULL;
        to->prev = tmp;
        *b = tmp;
    }
	write(1, "pb\n", 3);
}

void ra(l_list **a)
{
	l_list  *first;
    l_list  *last;
    l_list  *stack;

    stack = *a;
    if(!(stack && stack->next))
        return;
    first = stack;
    stack = stack->next;
    last = stack;
    while(last->next)
    {
        last = last->next;
    }
	last->next = first;
    first->next = NULL;
    first->prev = last;
    stack->prev = NULL;
    *a = stack;
	write(1, "ra\n", 3);
}

void rra(l_list **a)
{
	l_list 	*stack;
    l_list  *first;
    l_list  *last;

    first = *a;
    if(!(first && first->next))
        return;
    stack = first;
    while(stack->next->next)
        stack = stack->next;
    last = stack;
    stack = stack->next;
    stack->prev = NULL;
    stack->next = first;
    first->prev = stack;
    last->next = NULL;
    *a = stack;
    write(1,"rra\n", 4);
}

void	sb(l_list *a)
{
		int 	store;
		l_list 	*next;

		next = a->next;
		store = a->i;
		a->i = next->i;
		next->i = store;
		write(1, "sb\n", 3);
}

void	pa(l_list **b, l_list **a)
{
    static l_list  *tmp;
    static l_list  *to;
    static l_list  *from;

    to = *a;
    from = *b;
    if(!from)
        return;
    tmp = from;
    if (!(from->next))
        from = NULL;
    else
    {
        from = from->next;
        from->prev = NULL;
    }
    *b = from;
    if(!to)
    {
        to = tmp;
        to->next = NULL;
        to->prev = NULL;
        *a = to;
    }
    else
    {
        tmp->next = to;
        tmp->prev = NULL;
        to->prev = tmp;
        *a = tmp;
    }
	write(1, "pa\n", 3);
}

void rb(l_list **a)
{
	l_list  *first;
    l_list  *last;
    l_list  *stack;

    stack = *a;
    if(!(stack && stack->next))
        return;
    first = stack;
    stack = stack->next;
    last = stack;
    while(last->next)
    {
        last = last->next;
    }
	last->next = first;
    first->next = NULL;
    first->prev = last;
    stack->prev = NULL;
    *a = stack;
	write(1, "rb\n", 3);
}

void rrb(l_list **a)
{
	l_list 	*stack;
    l_list  *first;
    l_list  *last;

    first = *a;
    if(!(first && first->next))
        return;
    stack = first;
    while(stack->next->next)
        stack = stack->next;
    last = stack;
    stack = stack->next;
    stack->prev = NULL;
    stack->next = first;
    first->prev = stack;
    last->next = NULL;
    *a = stack;
    write(1,"rrb\n", 4);
}

int ft_check_sort(l_list *list)
{
    l_list *tmp;

    tmp = list;
    while (tmp->next)
    {
        if (tmp->i > tmp->next->i)
            return(0);
        tmp = tmp->next;
    }
    return(1);
}

void ft_sort3(l_list *a)
{
    l_list *node1;
    l_list *node2;
    l_list *node3;
    
    node1 = a;
    node2 = a->next;
    node3 = node2->next;
    if (node2->i < node1->i && node1->i < node3->i && node2->i < node3->i)
        sa(a);
    if (node1->i < node2->i && node1->i > node3->i && node2->i > node3->i)
        rra(&a);
    if (node1->i > node2->i && node1->i > node3->i && node2->i < node3->i)
        ra(&a);
    if (node1->i < node2->i && node1->i < node3->i && node2->i > node3->i)
    {
        rra(&a);
        sa(a);
    }
    if (node1->i > node2->i && node1->i > node3->i && node2->i > node3->i)
    {
        ra(&a);
        sa(a);
    }
}

int    find_min_node(l_list *stack)
{
    int     min;
    l_list  *tmp;
    int     index;

    min = INT_MAX;
    index = 0;
    tmp = stack;
    while (tmp)
    {
        if (tmp->i < min)
            min = tmp->i;
        tmp = tmp->next;
    }
    tmp = stack;
    while (tmp)
    {
        index++;
        if (tmp->i == min)
            return(index);
        tmp = tmp->next;
    }
    return(0);
}

int     list_len(l_list *stack)
{
    int     i;
    l_list  *tmp;

    i = 0;
    tmp = stack;
    while (tmp)
    {
        i++;
        tmp = tmp->next;
    }
    return (i);
}

/*void ft_sort3B(l_list *b)
{
    l_list *node1;
    l_list *node2;
    l_list *node3;
    
    node1 = b;
    if (!(b->next))
        return;
    node2 = b->next;
    if(!(b->next->next))
    {
        if(node1->i < node2->i)
        {
            sb(b);
            return;
        }
        else
            return;
    }
    node3 = b->next->next;
    if (node2->i < node1->i && node1->i < node3->i && node2->i < node3->i)
        rrb(&b);
    if (node1->i < node2->i && node1->i > node3->i && node2->i > node3->i)
        sb(b);
    if (node1->i > node2->i && node1->i > node3->i && node2->i < node3->i)
        rrb(&b);
        sb(b);

    if (node1->i < node2->i && node1->i < node3->i && node2->i > node3->i)
    {
        rb(&b);
    }
    if (node1->i > node2->i && node1->i > node3->i && node2->i > node3->i)
        return;
    if (node1->i < node2->i && node1->i < node3->i && node2->i < node3->i)
    {
        sb(b);
        rrb(&b);
    }
}*/

void ft_small_sort(l_list *a, int size)
{
    l_list  *node1 = a;
    l_list  *node2 = a->next;

    if (size == 2)
        return;
    if (size == 3)
    {
        if (node1->i > node2->i)
        {
            sa(a);
            return;
        }
        else
            return;
    }
    if (size == 4)
    {
        ft_sort3(a);
    }
}

int ft_average(l_list *list)
{
    int c;
    int sum;
    l_list  *tmp;

    c = 0;
    sum = 0;
    tmp = list;

    while (tmp->next)
    {
        sum += tmp->i;
        c++;
        tmp = tmp->next;
    }
    return(sum / c);
}

void ft_medium_sort(l_list *a, l_list *b, int sizea)
{
    int len;
    int index;
    int rep;
    int i;

    while (sizea > 4)
    {
        index = find_min_node(a);
        len = list_len(a);
        
        if (index <= ((len / 2) + 1))
        {
            rep = index - 1;
            i = 0;
            while (i < rep)
            {
                ra(&a);
                i++;
            }
            pb(&a, &b);
            sizea--;
        }
        if (index > ((len / 2) + 1))
        {
            rep = len - index + 1;
            i = 0;
            while (i < rep)
            {
                rra(&a);
                i++;
            }
            pb(&a, &b);
            sizea--;
        }
    }
    ft_sort3(a);
    while (b)
    {
        pa(&b, &a);
    }
}

void    print_list(l_list *stack, char stackname)
{
    if (!stack)
        printf("Node %c: Empty stack.", stackname);
    while (stack)
    {
        printf("Node %c: %i\n", stackname, stack->i);
        stack = stack->next;
    }
}

int main(int argc, char **argv)
{
    int i = 1;
    static l_list *stack_a;
    static l_list *stack_b;
    l_list *tmp_a;
    l_list *tmp_b;
    stack_a = ft_parse(argc, argv);
    if (argc == 2)
        argc = (count_words(argv[1], ' ') + 1);
    stack_b = NULL;
    
    if (ft_check_sort(stack_a) == 1)
        return (1);
    if (argc <= 4)
    {
        ft_small_sort(stack_a, argc);
        return (1);
    }
    else if (argc <= 7)
    {
        ft_medium_sort(stack_a, stack_b, argc);
        return (1);
    }
    else
    {
        ft_medium_sort(stack_a, stack_b, argc);
        return (1);
    }

    /*ra(&stack_a);
    pb(&stack_a, &stack_b);

    pb(&stack_a, &stack_b);

    pb(&stack_a, &stack_b);

    rra(&stack_a);
    sb(stack_b);

    pa(&stack_b, &stack_a);*/

    tmp_a = stack_a;
    tmp_b = stack_b;
    print_list(stack_a, 'A');
    print_list(stack_b, 'B');
}
    