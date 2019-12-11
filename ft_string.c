/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:49:15 by hthomas           #+#    #+#             */
/*   Updated: 2019/12/11 18:12:54 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_string(va_list arg, t_sp *sp, t_f *f)
{
	char	*str;

	sp->s = va_arg(arg, char*);
	if (!sp->s)
	{
		if (!(str = ft_strdup("(null)")))
			return (NULL);
	}
	else
	{
		if (!(str = ft_strdup(sp->s)))
			return (NULL);
	}
	if (f->precision)
	{
		if (!sp->i && !f->pr)
		{
			if (!(str = ft_chardup('\0')))
				return (NULL);
		}
		else
		{
			if (!(str = ft_concat(0, str, f->pr, '0')))
				return (NULL);
			if (f->precision && ft_strlen(str) > f->pr)
				str[f->pr] = '\0';
		}
	}
	if (f->width)
		if (!(str = ft_concat(f->minus, str, f->width, f->zero ? '0' : ' ')))
			return (NULL);
	return (str);
}
