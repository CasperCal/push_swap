/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaluwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:51:19 by ccaluwe           #+#    #+#             */
/*   Updated: 2021/11/03 15:51:22 by ccaluwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*Allocates (with malloc(3)) and returns an array
 of strings obtained by splitting ’s’ using the
 character ’c’ as a delimiter. The array must be
 ended by a NULL pointer.*/

int	count_words(const char *str, char c)
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
