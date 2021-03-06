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

#include "checker.h"

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

void	ft_check_int(int n, unsigned long long int res)
{
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
}

int	ft_check_atoi(char *str)
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
			exit(1);
		}
		res = (res * 10) + (str[i++] - '0');
	}
	ft_check_int(n, res);
	return (res * n);
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

void	ft_check_dupli(char **str)
{
	int		i;
	int		j;
	char	*cmp;

	i = 0;
	while (str[i])
	{
		cmp = ft_strdup(str[i]);
		j = 0;
		while (str && str[j])
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
		free(cmp);
		i++;
	}
}
