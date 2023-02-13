/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:23:35 by voszadcs          #+#    #+#             */
/*   Updated: 2023/01/30 16:02:56 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s != NULL && s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s && s[i] != 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == 0 && (char)c == 0)
		return ((char *)&s[i]);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		size1;
	int		size2;

	size1 = ft_strlen((char *)s1);
	size2 = ft_strlen((char *)s2);
	i = 0;
	str = malloc(size1 + size2 + 1);
	if (!str)
		return (NULL);
	while (s1 && *s1 != 0)
	{
		str[i++] = *(char *)s1++;
	}
	while (s2 && *s2 != 0)
	{
		str[i++] = *(char *)s2++;
	}
	str[i] = '\0';
	return (str);
}

void	*ft_memmove(char *dest, char *src, size_t n)
{
	size_t	i;
	size_t	size;

	size = n;
	i = -1;
	if (!dest && !src)
		return (0);
	if (dest < src)
	{
		while (++i < n)
			dest[i] = src[i];
	}
	else
	{
		while (n > 0)
		{
			dest[n - 1] = src[n - 1];
			n--;
		}
	}
	dest[size] = '\0';
	return (dest);
}
