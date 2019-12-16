/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:49:15 by hthomas           #+#    #+#             */
/*   Updated: 2019/12/16 06:17:43 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_percent(va_list arg, t_sp *sp, t_f *f)
{
	char	*str;

	(void)arg;
	sp->i = '%';
	if (!(str = ft_chardup(sp->i)))
		return (NULL);
	/*if (f->precision)
	{
		if (!(str = ft_cat(0, str, f->pr + 1, '0')))
			return (NULL);
	}*/
	if (f->width || f->zero)
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
