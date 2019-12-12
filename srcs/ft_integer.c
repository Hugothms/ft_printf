/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:49:15 by hthomas           #+#    #+#             */
/*   Updated: 2019/12/12 14:32:34 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*precision_integer(char *str, t_sp *sp, t_f *f)
{
	int		len;

	if (f->precision)
	{
		len = ft_strlen(str);
		if (!sp->i && !f->pr)
		{
			if (!(str = ft_chardup('\0')))
				return (NULL);
		}
		else if (sp->i < 0 && f->precision && f->pr > len)
		{
			if (!(str = ft_concat(0, str, f->pr, '0')))
				return (NULL);
			str[f->pr - len] = '0';
			if (!(str = ft_strjoin(ft_chardup('-'), str)))
				return (NULL);
		}
		else
		{
			if (!(str = ft_concat(0, str, f->pr, '0')))
				return (NULL);
		}
	}
	return (str);
}

char	*ft_integer(va_list arg, t_sp *sp, t_f *f)
{
	char	*str;
	int		len;

	sp->i = va_arg(arg, int);
	if (!(str = ft_itoa(sp->i)))
		return (NULL);
	str = precision_integer(str, sp, f);
	if (f->width)
	{
		len = ft_strlen(str);
		if (sp->i < 0 && f->width > len && f->zero)
		{
			if (!(str = ft_concat(0, str, f->width - 1, '0')))
				return (NULL);
			str[f->width - len - 1] = '0';
			if (!(str = ft_strjoin(ft_chardup('-'), str)))
				return (NULL);
		}
		else
		{
			if (!(str = ft_concat(f->minus, str, f->width, f->zero ? '0' : ' ')))
			return (NULL);
		}
	}
	return (str);
}
