/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 05:31:16 by voszadcs          #+#    #+#             */
/*   Updated: 2022/12/12 08:04:47 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	specifier(char c, va_list args)
{
	if (c == '%')
		return (write(1, "%", 1));
	if (c == 'd')
		return (write_nbr(va_arg(args, int)));
	if (c == 'i')
		return (write_nbr(va_arg(args, int)));
	else if (c == 'c')
		return (write_char(va_arg(args, int)));
	else if (c == 's')
		return (write_string(va_arg(args, char *)));
	else if (c == 'p')
		return (write_pointer(va_arg(args, unsigned long long)));
	if (c == 'u')
		return (write_unbr(va_arg(args, unsigned int)));
	if (c == 'x' || c == 'X')
		return (write_hex(va_arg(args, unsigned int), c));
	return (0);
}
