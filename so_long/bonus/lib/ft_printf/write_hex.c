/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 06:00:23 by voszadcs          #+#    #+#             */
/*   Updated: 2022/12/12 08:04:52 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned int n, char c)
{
	if (n >= 16)
		return (print_hex(n / 16, c) + print_hex(n % 16, c));
	else
	{
		if (n <= 9)
			write_char(n + 48);
		else if (c == 'x')
			write_char(n - 10 + 'a');
		else
			write_char(n - 10 + 'A');
	}
	return (1);
}

int	write_hex(unsigned int n, char c)
{
	return (print_hex(n, c));
}
