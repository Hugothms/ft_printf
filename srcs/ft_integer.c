/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:49:15 by hthomas           #+#    #+#             */
/*   Updated: 2019/12/16 04:18:28 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*pansement(char *str)
{
	int		is;
	int		idf;
	int		fds;
	int		fdf;
	char	c;

	is = 0;
	idf = 0;
	while (idf < (int)ft_strlen(str) && !(fdf = in_charset(str[idf], " ")))
		idf++;
	while (is < (int)ft_strlen(str) && !(fds = in_charset(str[is], "0")))
		is++;
	if (fds && fdf)
	{
		c = str[is];
		str[is] = str[idf];
		str[idf] = c;
	}
	return (str);
}

char	*ft_integer(va_list arg, t_sp *sp, t_f *f)
{
	char	*str;

	sp->i = va_arg(arg, int);
	if (!(str = ft_itoa(sp->i)))
		return (NULL);
	// ft_putstr("|");
	// ft_putstr(str);
	// ft_putstr("|");
	if (f->precision)
	{
		if (!(str = precision_integer(str, sp, f)))
			return (NULL);
	}
	// ft_putstr("|");
	// ft_putstr(str);
	// ft_putstr("|");
	if (!(str = ft_add_sign(str, sp, f)))
		return (NULL);
	// ft_putstr("|");
	// ft_putstr(str);
	// ft_putstr("|");
	if (!(str = width_integer(str, f)))
		return (NULL);
	// ft_putstr("|");
	// ft_putstr(str);
	// ft_putstr("|");
	if (!(str = keep_position_sign(str)))
		return (NULL);
	if (!())
	{
		if (!(str = pansement(str)))
			return (NULL);
	}
	return (str);
}
