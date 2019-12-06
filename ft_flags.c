/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:07:56 by hthomas           #+#    #+#             */
/*   Updated: 2019/12/06 17:47:29 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_get_flags(const char *fmt, t_sp *sp, t_f *f)
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

void	ft_get_width(const char *fmt, t_sp *sp, t_f *f, va_list arg)
{
	if (fmt[sp->index] == '*')
	{
		f->width = va_arg(arg, int);
		if (f->width < 0)
		{
			f->width *= -1;
			f->za = 1;
		}
		sp->index++;
	}
	else
	{
		f->width = ft_atoi_no_sign(&fmt[sp->index]);
		while (ft_isdigit(fmt[sp->index]))
			sp->index++;
	}
}

void	ft_get_precision(const char *fmt, t_sp *sp, t_f *f, va_list arg)
{
	if (fmt[sp->index] == '.')
	{
		sp->index++;
		if (fmt[sp->index] == '*')
		{
			f->pr = va_arg(arg, int);
			if (f->pr < 0)
			{
				f->pr *= -1;
				f->zb = 1;
			}
			sp->index++;
		}
		else
		{
			f->pr = ft_atoi_no_sign(&fmt[sp->index]);
			while (ft_isdigit(fmt[sp->index]))
				sp->index++;
		}
	}
}
