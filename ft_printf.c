/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:42:33 by hthomas           #+#    #+#             */
/*   Updated: 2019/12/10 18:10:03 by hthomas          ###   ########.fr       */
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
		return (ft_hex(arg, sp, 1));
	else if (fmt[sp->index] == 'X')
		return (ft_hex(arg, sp, 0));
	if (in_charset(fmt[sp->index], "cspdiuxX%"))
		return (ft_chardup('%'));
	return (NULL);
}

void	ft_put_clean(t_sp *sp, t_f *f, char *str)
{
	if (!f->pr && !ft_strcmp(str,"0"))
		sp->len--;
	else if (!f->pr && !ft_strcmp(str,"0x0"))
	{
		ft_putstrn(str,  2);
		sp->len -= 1;
	}
	else if (!f->pr && !ft_strcmp(str,"(null)"))
		sp->len -= 6;
	else if (sp->i)
		ft_putstr(str);
	else
	{
		ft_putstrn(str,  f->width > f->pr ? f->pr : f->pr);
		sp->len -= ft_strlen(str) - f->pr + 1;
	}
}

void ft_show(t_sp *sp, t_f *f, char *str)
{
	int				len;

	len = ft_strlen(str);
	if (f->width)
	{
		if (*str == '-' && sp->i && f->precision)
		{
			ft_putchar('-');
			str++;
			f->pr++;
		}
		if (f->zero)
			ft_zeros(f->width, sp, f->precision ? f->pr : len);
		else if (!f->minus)
			ft_spaces(f->width, sp, f->precision && f->pr ? f->pr : len);
	}
	if (f->precision && (sp->i || sp->u || sp->h))
		ft_zeros(f->pr, sp, len);
	if (f->width || f->precision)
		ft_put_clean(sp, f, str);
	else
		ft_putstr(str);
	if (f->width)
	{
		if (f->minus)
			ft_spaces(f->width, sp, f->precision ? f->pr : len);
	}
}


int		ft_printf_continue(const char *fmt, va_list arg, t_sp *sp)
{
	t_f				*f;
	char			*str;
	int				tmp;

	sp->index++;
	f = init_f();
	ft_get_flags(fmt, sp, f);
	ft_get_width(fmt, sp, f, arg);
	ft_get_precision(fmt, sp, f, arg);
	if(!(str = ft_conversion(fmt, arg, sp)))
		return (ERR);
	tmp = ft_strlen(str);
	if (sp->s && f->precision && f->pr < tmp)
		tmp = f->pr;
	sp->len += tmp;
	ft_show(sp, f, str);
	free(str);
	//free(f);
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
