/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 06:48:10 by voszadcs          #+#    #+#             */
/*   Updated: 2022/12/12 08:04:57 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_pointer(unsigned long long n)
{
	if (n >= 16)
		return (print_pointer(n / 16) + print_pointer(n % 16));
	else
	{
		if (n <= 9)
			write_char(n + 48);
		else
			write_char(n - 10 + 'a');
	}
	return (1);
}

int	write_pointer(unsigned long long n)
{
	return (write_string("0x") + print_pointer(n));
}
