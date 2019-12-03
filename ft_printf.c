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
	sp->index++;
	if (fmt[sp->index] == 'c')
		ft_char(fmt, arg, sp);
	else if (fmt[sp->index] == 's')
		ft_string(fmt, arg, sp);
	else if (fmt[sp->index] == 'p')
		ft_pointer(fmt, arg, sp);
	else if (fmt[sp->index] == 'd' || fmt[sp->index] == 'i')
		ft_integer(fmt, arg, sp);
	else if (fmt[sp->index] == 'u')
		ft_unsigned_int(fmt, arg, sp);
	else if (fmt[sp->index] == 'x')
		ft_hex(fmt, arg, sp, 0);
	else if (fmt[sp->index] == 'X')
		ft_hex(fmt, arg, sp, 1);
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

char	*ft_show(t_sp *sp, char type)
{
	if (type == 'c')
		return (ft_chardup(sp->i));
	else if (type == 's')
		return (ft_strdup(sp->s));
	else if (type == 'p')
		return (ft_strjoin(ft_strdup("0x"), ft_ulltoa(sp->p)));
	else if (type == 'd' || type == 'i')
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

void	ft_get_flags(const char *fmt, t_sp *sp, t_f	*f)
{
	while (in_charset(fmt[sp->index], "-0"))
	{
		if (fmt[sp->index] == '-' && !f->za)
		{
			f->za = 1;
			f->zb = 0;
		}
		else if (fmt[sp->index] == '0' && !f->zb && !f->za)
			f->zb = 1;
		sp->index++;
	}
}

void	ft_get_width(const char *fmt, t_sp *sp, t_f	*f)
{
	f->width = ft_atoi_no_sign(&fmt[sp->index]);
	while (ft_isdigit(fmt[sp->index]))
		sp->index++;
}

void	ft_get_precision(const char *fmt, t_sp *sp, t_f	*f)
{
	if (fmt[sp->index] == '.')
	{
		sp->index++;
		f->pr = ft_atoi_no_sign(&fmt[sp->index]);
		while (ft_isdigit(fmt[sp->index]))
			sp->index++;
	}
}

int		ft_printf_continue(const char *fmt, va_list arg, t_sp *sp)
{
	t_f		*f;
	char	type;
	char	*str;

	sp->index++;
	// printf("\ninital:|%s|\n", &fmt[sp->index]);
	f = init_f();
	ft_get_flags(fmt, sp, f);
	// printf("\nflag0:%d\n", f->zb);
	// printf("|%s|\n", &fmt[sp->index]);
	ft_get_width(fmt, sp, f);
	//ft_get_precision(fmt, sp, f);
	// printf("\n|%s|\n", &fmt[sp->index]);
	type = ft_conversion(fmt, arg, sp);
	if (f->zb)
	{
		// printf("on est la\n");
		ft_put_zeros(f->width, sp, ft_strlen(str));
	}
	// printf("ok\n");
	str = ft_show(sp, type);
	if (f->za)
	{
		// printf("on est ici\n");
		ft_put_zeros(f->width, sp, ft_strlen(str));
	}
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
