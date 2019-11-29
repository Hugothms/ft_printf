/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:42:33 by hthomas           #+#    #+#             */
/*   Updated: 2019/11/29 18:30:07 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize(t_sp sp)
{
	sp.d = 0;
	sp.u = 0;
	sp.s = NULL;
	sp.p = 0;
}

int		function(const char *fmt, va_list arg, t_sp sp)
{
	//ft_flags();
	if (fmt[sp.index] == 'c')
		ft_char(fmt, arg, sp);
	else if (fmt[sp.index] == 's')
		ft_string(fmt, arg, sp);
	else if (fmt[sp.index] == 'p')
		ft_pointer(fmt, arg, sp);
	else if (fmt[sp.index] == 'd' || fmt[sp.index] == 'i')
		ft_integer(fmt, arg, sp);
	else if (fmt[sp.index] == 'u')
		ft_unsigned_int(fmt, arg, sp);
	else if (fmt[sp.index] == 'x'|| fmt[sp.index] == 'X')
		fmt[sp.index] == 'x' ? ft_hex(fmt, arg, sp) : ft_hex(fmt, arg, sp);
	else if (fmt[sp.index] == '%')
	{
		ft_putchar('%');
		sp.len++;
	}
	sp.index++;
	return (0);
}

int		ft_printf(const char *fmt, ...)
{
	va_list	arg;
	t_sp	sp;

	va_start(arg, fmt);
	sp.index = 0;
	sp.len = 0;
	while (fmt[sp.index])
	{
		initialize(sp);
		if (fmt[sp.index] == '%')
		{
			function(fmt, arg, sp);
		}
		else
		{
			ft_putchar(fmt[sp.index]);
			sp.len++;
		}
		sp.index++;
	}
	va_end(arg);
	return (sp.len);
}

// * CONVERSIONS:	c	s	p	d	i	u	x	X	%
// * ANY COMB:		-0.*
// * F. AUTORISÉES:	malloc, free, write, va_start, va_arg, va_copy, va_end
