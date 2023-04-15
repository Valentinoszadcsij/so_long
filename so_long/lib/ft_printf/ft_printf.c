/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:43:31 by voszadcs          #+#    #+#             */
/*   Updated: 2022/12/12 08:11:02 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		print_length;

	va_start(args, s);
	i = 0;
	print_length = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '%')
			write_char(s[i]);
		else if (s[i] == '%')
		{
			i++;
			print_length += specifier(s[i], args) - 2;
		}
		i++;
	}
	va_end(args);
	return (i + print_length);
}
