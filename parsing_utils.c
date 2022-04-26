/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaluwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:10:20 by ccaluwe           #+#    #+#             */
/*   Updated: 2022/04/25 12:11:54 by ccaluwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
				free(cmp);
                write(1, "Error\n", 6);
                exit (1);
            }
            else
                j++;
        }
        i++;
    }
	free(cmp);
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
