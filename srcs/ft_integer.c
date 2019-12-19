/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:49:15 by hthomas           #+#    #+#             */
/*   Updated: 2019/12/19 16:11:22 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*just_do_it(char *str, t_sp *sp, t_f *f)
{
	ft_putstr(str);
	ft_putstr("|\n");
	if (f->precision)
	{
		if (!(str = precision_integer(str, sp, f)))
			return (NULL);
	}
	ft_putstr("|");
	ft_putstr(str);
	ft_putstr("|\n");
	if (!f->zero && sp->i != INT_MIN)
	{
		if (!(str = ft_add_sign(str, sp, f)))
			return (NULL);
	}
	ft_putstr("|");
	ft_putstr(str);
	ft_putstr("|\n");
	if (!(str = width_integer(str, sp, f)))
		return (NULL);
	ft_putstr("|");
	ft_putstr(str);
	ft_putstr("|\n|");
	if (f->zero && f->precision)
	{
		if (!(str = ft_add_sign(str, sp, f)))
			return (NULL);
	}
	return (str);
}

char	*ft_integer(va_list arg, t_sp *sp, t_f *f)
{
	char	*str;
	int		ok;

	sp->i = va_arg(arg, int);
	if (sp->i < 0 && (ok = 1))
		sp->i *= -1;
	if (!(str = ft_itoa(sp->i)))
		return (NULL);
	sp->i *= (ok == 1 ? -1 : 1);
	if (!(str = just_do_it(str, sp, f)))
		return (NULL);
	return (str);
}
