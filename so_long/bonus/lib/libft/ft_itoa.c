/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 04:40:06 by voszadcs          #+#    #+#             */
/*   Updated: 2023/03/25 21:28:22 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

static int	itoa_len(long int n, int i)
{
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*fill(long int num, int i, char *buff, int len)
{
	if (num < 0)
	{
		num = num * -1;
		buff[0] = '-';
		while (i > 0)
		{
			buff[i] = num % 10 + '0';
			num = num / 10;
			i--;
		}
		buff[len] = '\0';
		return (buff);
	}
	while (i >= 0)
	{
		buff[i] = num % 10 + '0';
		num = num / 10;
		i--;
	}
	buff[len] = '\0';
	return (buff);
}

char	*ft_itoa(int n)
{
	char		*buff;
	long int	num;
	int			len;
	int			i;

	num = (long int)n;
	len = itoa_len(num, 1);
	i = len -1;
	buff = malloc(len + 1);
	if (!buff)
		return (NULL);
	return (fill(num, i, buff, len));
}
