/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:49:15 by hthomas           #+#    #+#             */
/*   Updated: 2019/12/12 14:03:27 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_percent(t_sp *sp, t_f *f)
{
	char 	*str;

	sp->i = '%';
	if (!(str = ft_chardup(sp->i)))
		return (NULL);
	if (f->precision)
	{
		if (!(str = ft_concat(0, str, f->pr, '0')))
			return (NULL);
	}
	if (f->width)
	{
		if (!(str = ft_concat(f->minus, str, f->width, f->zero ? '0' : ' ')))
			return (NULL);
		if (!sp->i)
			str[f->width - 1] = '\0';
	}
	if(!sp->i)
		sp->len++;
	return (str);
}
