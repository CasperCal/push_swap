/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaluwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:27:14 by ccaluwe           #+#    #+#             */
/*   Updated: 2022/05/05 15:27:31 by ccaluwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_strcat(char *dest, char *src)
{
	size_t	dlen;
	size_t	slen;

	if (!dest)
		return (ft_strdup(src));
	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	dest = (char *) ft_realloc(dest, dlen + slen + 1);
	ft_strcpy(dest + dlen, src);
	return (dest);
}

void	*ft_realloc(void *ptr, size_t new_size)
{
	size_t	current_size;
	void	*new_ptr;

	if (!ptr)
		return (malloc(new_size));
	current_size = ft_strlen((char *) ptr);
	if (current_size > new_size)
		return (ptr);
	new_ptr = malloc(new_size);
	new_ptr = ft_memcpy(new_ptr, ptr, current_size);
	free(ptr);
	return (new_ptr);
}

char	*ft_strcpy(char *dest, char *src)
{
	return (ft_memcpy(dest, src, ft_strlen(src) + 1));
}

int	error_exit(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*p_dst;
	char	*p_src;

	if (!n)
		return (dst);
	if (!dst && !src)
		return (NULL);
	p_dst = (char *) dst;
	p_src = (char *) src;
	i = 0;
	while (i++ < n)
		*p_dst++ = *p_src++;
	return (dst);
}
