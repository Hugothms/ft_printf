/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:49:15 by hthomas           #+#    #+#             */
/*   Updated: 2019/12/12 12:00:36 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_pointer(va_list arg, t_sp *sp, t_f *f)
{
	char	*bl;
	char	*str;
	char	*tmp;

	bl = "0123456789abcdef";
	sp->p = va_arg(arg, long);
	if (!(str = ft_ltoa_base(sp->p, bl)))
		return (NULL);
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
		}
	}
	tmp = str;
	if (!(str = ft_strjoin(ft_strdup("0x"), tmp)))
		return (NULL);
	free(tmp);
	if (f->width)
		if (!(str = ft_concat(f->minus, str, f->width, f->zero ? '0' : ' ')))
			return (NULL);
	return (str);
}
