/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 10:05:27 by voszadcs          #+#    #+#             */
/*   Updated: 2022/12/12 08:04:54 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_nbr(int n)
{
	if (n < 0)
	{
		write(1, "-", 1);
		if (n == -2147483648)
			return (write_string("2147483648") + 1);
		n = n * -1;
		return (write_nbr(n) + 1);
	}
	if (n >= 10)
		return (write_nbr(n / 10) + write_nbr(n % 10));
	else
	{
		if (n >= 0)
			write_char(n + 48);
	}
	return (1);
}
