/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 10:07:31 by voszadcs          #+#    #+#             */
/*   Updated: 2022/12/12 08:11:11 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include	<unistd.h>
# include	<stdarg.h>
# include	<stdlib.h>

int		ft_printf(const char *s, ...);
int		write_nbr(int n);
int		write_char(char c);
int		write_string(char *s);
size_t	length(const char *s);
int		specifier(char c, va_list args);
int		write_pointer(unsigned long long n);
int		write_unbr(unsigned int n);
int		write_hex(unsigned int n, char c);

#endif