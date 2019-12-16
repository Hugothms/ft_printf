/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:49:15 by hthomas           #+#    #+#             */
/*   Updated: 2019/12/16 04:05:53 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_add_sign(char *str, t_sp *sp, t_f *f)
{
	char	*tmp;
	char	*tmpchar;
	char	sign;

	if (sp->i >= 0 && (f->space || f->plus) && !(!sp->i && f->space))
	{
		if (sp->i >= 0)
			sign = f->space ? ' ' : '+';
		else
			sign = '-';
		tmp = str;
		if (!(tmpchar = ft_chardup(sign)))
			return (NULL);
		if (!(str = ft_strjoin(tmpchar, str)))
			return (NULL);
		free(tmp);
		free(tmpchar);
	}
	return (str);
}

char	*precision_sign(char *str, t_f *f)
{
	if (f->space || f->plus)
	{
		free(str);
		if (!(str = ft_chardup(f->space ? ' ' : '+')))
			return (NULL);
	}
	else
	{
		free(str);
		if (!(str = ft_chardup('\0')))
			return (NULL);
	}
	return (str);
}

char	*precision_integer(char *str, t_sp *sp, t_f *f)
{
	int		len;

	len = ft_strlen(str);
	if (!sp->i && !f->pr)
	{
		if (!(str = precision_sign(str, f)))
			return (NULL);
	}
	else if (f->precision && f->pr >= len)
	{
		if (!(str = ft_cat(0, str, f->pr + (sp->i < 0), '0')))
			return (NULL);
	}
	else
	{
		if (!(str = ft_cat(0, str, f->pr, '0')))
			return (NULL);
	}
	return (str);
}

char	*width_integer(char *str, t_f *f)
{
	if (f->width)
	{
		if (!(str = ft_cat(f->minus, str, f->width, f->zero ? '0' : ' ')))
			return (NULL);
	}
	return (str);
}

char	*keep_position_sign(char *str)
{
	int		is;
	int		idf;
	int		fds;
	int		fdf;
	char	c;

	is = 0;
	idf = 0;
	while (idf < (int)ft_strlen(str) && !(fdf = in_charset(str[idf], "-")))
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
