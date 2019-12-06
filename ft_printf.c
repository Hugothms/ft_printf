/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:42:33 by hthomas           #+#    #+#             */
/*   Updated: 2019/12/06 16:48:57 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conversion(const char *fmt, va_list arg, t_sp *sp)
{
	if (fmt[sp->index] == 'c')
		return (ft_char(arg, sp));
	else if (fmt[sp->index] == 's')
		return (ft_string(arg, sp));
	else if (fmt[sp->index] == 'p')
		return (ft_pointer(arg, sp));
	else if (fmt[sp->index] == 'd' || fmt[sp->index] == 'i')
		return (ft_integer(arg, sp));
	else if (fmt[sp->index] == 'u')
		return (ft_unsigned_int(arg, sp));
	else if (fmt[sp->index] == 'x')
		return (ft_hex(arg, sp, 0));
	else if (fmt[sp->index] == 'X')
		return (ft_hex(arg, sp, 1));
	if (in_charset(fmt[sp->index], "cspdiuxX%"))
		return (ft_chardup('%'));
	return (NULL);
}

void ft_show(t_sp *sp, t_f *f, char *str)
{
	unsigned long	len;

	len = ft_strlen(str);
	if (f->zb && f->width > f->pr)
		f->pr ? ft_spaces(f->width, sp, f->pr) : ft_zeros(f->width, sp, len);
	else if (f->zb && f->width > f->pr)
		ft_zeros(f->width, sp, f->pr ? f->pr : len);
	if ((f->zb || f->za) && f->pr && f->pr > len)
		ft_zeros(f->pr, sp, len);
	if (sp->s && f->pr)
		ft_putstrn(str, f->pr);
	else
		ft_putstr(str);
	if (f->za && f->width && f->width > f->pr)
		ft_spaces(f->width, sp, f->pr ? f->pr : len);
}


int		ft_printf_continue(const char *fmt, va_list arg, t_sp *sp)
{
	t_f				*f;
	char			*str;
	unsigned long	tmp;

	sp->index++;
	f = init_f();
	ft_get_flags(fmt, sp, f);
	ft_get_width(fmt, sp, f, arg);
	ft_get_precision(fmt, sp, f, arg);
	if(!(str = ft_conversion(fmt, arg, sp)))
		return (ERR);
	tmp = ft_strlen(str);
	if (sp->s && f->pr && f->pr < tmp)
		tmp = f->pr;
	sp->len += tmp;
	ft_show(sp, f, str);
	free(str);
	return (OK);
}

int		ft_printf(const char *fmt, ...)
{
	va_list	arg;
	t_sp	*sp;
	int		len;

	va_start(arg, fmt);
	if (!(sp = init_sp()))
		return (ERR);
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
