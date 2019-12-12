/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:42:33 by hthomas           #+#    #+#             */
/*   Updated: 2019/12/12 17:55:49 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_conversion(const char *fmt, va_list arg, t_sp *sp, t_f *f)
{
	if (fmt[sp->index] == 'c')
		return (ft_char(arg, sp, f));
	else if (fmt[sp->index] == 's')
		return (ft_string(arg, sp, f));
	else if (fmt[sp->index] == 'p')
		return (ft_pointer(arg, sp, f));
	else if (fmt[sp->index] == 'd' || fmt[sp->index] == 'i')
		return (ft_integer(arg, sp, f));
	else if (fmt[sp->index] == 'u')
		return (ft_unsigned_int(arg, sp, f));
	else if (fmt[sp->index] == 'x')
		return (ft_hex(arg, sp, f, 1));
	else if (fmt[sp->index] == 'X')
		return (ft_hex(arg, sp, f, 0));
	else if (fmt[sp->index] == '%')
		return (ft_percent(sp, f));
	return (NULL);
}

int		ft_printf_continue(const char *fmt, va_list arg, t_sp *sp)
{
	t_f				*f;
	char			*str;

	sp->index++;
	f = init_f();
	ft_get_flags(fmt, sp, f);
	ft_get_width(fmt, sp, f, arg);
	ft_get_precision(fmt, sp, f, arg);
	if (!(str = ft_conversion(fmt, arg, sp, f)))
		return (ERR);
	sp->len += ft_strlen(str);
	ft_putstr(str);
	free(str);
	free(f);
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
