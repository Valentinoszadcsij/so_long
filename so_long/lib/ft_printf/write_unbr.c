/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_unbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 05:49:58 by voszadcs          #+#    #+#             */
/*   Updated: 2022/12/12 08:05:03 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_unbr(unsigned int n)
{
	if (n >= 10)
		return (write_nbr(n / 10) + write_nbr(n % 10));
	else
		write_char(n + 48);
	return (1);
}
