/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:49:15 by hthomas           #+#    #+#             */
/*   Updated: 2019/12/12 17:50:54 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_char(va_list arg, t_sp *sp, t_f *f)
{
	char	*str;

	sp->i = va_arg(arg, int);
	if (!(str = ft_chardup(sp->i)))
		return (NULL);
	if (f->precision)
	{
		if (!(str = ft_cat(0, str, f->pr, '0')))
			return (NULL);
	}
	if (f->width)
	{
		if (!(str = ft_cat(f->minus, str, f->width, f->zero ? '0' : ' ')))
			return (NULL);
		if (!sp->i)
			str[f->width - 1] = '\0';
	}
	if (!sp->i)
		sp->len++;
	return (str);
}
