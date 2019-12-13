/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:49:15 by hthomas           #+#    #+#             */
/*   Updated: 2019/12/13 18:39:37 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_integer(va_list arg, t_sp *sp, t_f *f)
{
	char	*str;

	sp->i = va_arg(arg, int);
	if (!(str = ft_itoa(sp->i)))
		return (NULL);
	if (!(str = ft_add_sign(str, sp, f)))
		return (NULL);
	if (f->precision)
	{
		if (!(str = precision_integer(str, sp, f)))
			return (NULL);
	}
	if (!(str = width_integer(str, f)))
		return (NULL);
	if ((sp->i < 0 || f->plus || f->space) && !f->minus)
	{
		if (!(str = keep_position_sign(str)))
			return (NULL);
	}
	return (str);
}
