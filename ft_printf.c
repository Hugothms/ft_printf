/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf->c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:42:33 by hthomas           #+#    #+#             */
/*   Updated: 2019/12/03 16:31:55 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include<stdio.h>

char	ft_conversion(const char *fmt, va_list arg, t_sp *sp)
{
	// int	len;

	// len = sp->len;
	if (fmt[sp->index] == 'c')
		return(ft_char(arg, sp));
	else if (fmt[sp->index] == 's')
		return(ft_string(arg, sp));
	else if (fmt[sp->index] == 'p')
		return(ft_pointer(arg, sp));
	else if (fmt[sp->index] == 'd' || fmt[sp->index] == 'i')
		return(ft_integer(arg, sp));
	else if (fmt[sp->index] == 'u')
		return(ft_unsigned_int(arg, sp));
	else if (fmt[sp->index] == 'x')
		return(ft_hex(arg, sp));
	else if (fmt[sp->index] == 'X')
		return(ft_hex(arg, sp));
	else if (fmt[sp->index] == '%')
	{
		sp->i = '%';
		sp->len++;
	}
	if (in_charset(fmt[sp->index], "cspdiuxX%"))
		return (fmt[sp->index]);
	return (0);
	// return (sp->len - len);
}

char	*ft_get_str_from_struct(t_sp *sp, char type)
{
	if (type == 'c')
	{
		// printf("y");
		return (ft_chardup(sp->i));
	}
	else if (type == 's')
		return (ft_strdup(sp->s));
	else if (type == 'p')
		return (ft_strjoin(ft_strdup("0x"), ft_ltoa_base(sp->p, "0123456789abcdef")));
	else if (type == 'i')
		return (ft_itoa(sp->i));
	else if (type == 'u')
		return (ft_uitoa(sp->u));
	// else if (type == 'x')
	// 	return (ft_puthex(sp->h, 0));
	// else if (type == 'X')
	// 	return (ft_puthex(sp->h, 1));
	else if (type == '%')
	 	return (ft_chardup(sp->i));
	return (NULL);
}

int		ft_printf_continue(const char *fmt, va_list arg, t_sp *sp)
{
	t_f		*f;
	char	type;
	char	*str;

	sp->index++;
	f = init_f();
	ft_get_flags(fmt, sp, f);
	ft_get_width(fmt, sp, f);
	//ft_get_precision(fmt, sp, f);
	type = ft_conversion(fmt, arg, sp);
	str = ft_get_str_from_struct(sp, type);
	if (f->zb)
	{
		//printf("str: |%s|\n", str);
		ft_put_zeros(f->width, sp, ft_strlen(str));
	}
	ft_putstr(str);
	if (f->za)
	{
		ft_put_spaces(f->width, sp, ft_strlen(str));
	}
	free(str);
	return (0);
}

int		ft_printf(const char *fmt, ...)
{
	va_list	arg;
	t_sp	*sp;
	int 	len;

	va_start(arg, fmt);
	if(!(sp = init_sp()))
		return (-1);
	while (fmt[sp->index])
	{
		reset_sp(sp);
		if (fmt[sp->index] == '%')
			ft_printf_continue(fmt, arg, sp);
		else
		{
			ft_putchar(fmt[sp->index]);
			sp->len++;
		}
		sp->index++;
	}
	len = sp->len;
	free_sp(sp);
	va_end(arg);
	return (len);
}
