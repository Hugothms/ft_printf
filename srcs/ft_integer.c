/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:49:15 by hthomas           #+#    #+#             */
/*   Updated: 2019/12/16 17:52:44 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*pansement(char *str)
{
	free(str);
	if (!(str = ft_chardup('+')))
		return (NULL);
	return (str);
}

char	*bandage(char *str)
{
	int		is;
	int		idf;
	int		fds;
	int		fdf;
	char	c;

	is = 0;
	idf = 0;
	while (idf < (int)ft_strlen(str) &&
	!(fdf = in_charset(str[idf], "0")))
		idf++;
	while (is < (int)ft_strlen(str) && !(fds = in_charset(str[is], "+")))
		is++;
	if (fds && fdf)
	{
		c = str[is];
		str[is] = str[idf];
		str[idf] = c;
		return (str);
	}
	return (str);
}

char	*creme(char *str, t_f *f)
{
	char	*tmp;
	int		max;

	max = f->width > f->pr ? f->width : f->pr;
	tmp = str;
	if (!(str = malloc((max + 1) * sizeof(char))))
		return (NULL);
	free(tmp);
	str[max] = '\0';

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
	ft_putstr("|");
	ft_putstr(str);
	ft_putstr("|");
	if (f->precision)
	{
		if (!(str = precision_integer(str, sp, f)))
			return (NULL);
	}
	ft_putstr("|");
	ft_putstr(str);
	ft_putstr("|");
	if (!f->zero)
	{
		if (!(str = ft_add_sign(str, sp, f)))
			return (NULL);
	}
	ft_putstr("|");
	ft_putstr(str);
	ft_putstr("|");
	if (!(str = width_integer(str, sp, f)))
		return (NULL);
	ft_putstr("|");
	ft_putstr(str);
	ft_putstr("|");
	if (f->zero)
	{
		if (!(str = ft_add_sign(str, sp, f)))
			return (NULL);
	}
	// if (!sp->i)
	// {
	// 	if (!(str = keep_position_sign(str, !sp->i 	&&
	// 	f->plus && !f->minus && in_charset(' ', str))))
	// 		return (NULL);
	// }
	ft_putstr("|");
	ft_putstr(str);
	ft_putstr("|");
	if (!sp->i && f->plus && f->precision && !f->pr && f->width < 2)
	{
		if (!(str = pansement(str)))
			return (NULL);
	}
	// if (!sp->i && f->plus && !f->minus && ((!f->precision && f->width > 2) || (f->precision && (f->pr + 1 < f->width))))
	// {
	// 	if (!(str = bandage(str)))
	// 		return (NULL);
	// }
	// if (sp->i && f->plus && (!f->precision || ((f->width > f->pr) && f->precision)))
	// {
	// 	if (!(str = creme(str, f)))
	// 		return (NULL);
	// }
	return (str);
}
