/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:49:15 by hthomas           #+#    #+#             */
/*   Updated: 2019/12/13 13:43:00 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_sign(char *str, t_sp *sp, t_f *f)
{
	char	*tmp;
	char	*tmpchar;
	int		len;

	len = ft_strlen(str);
	if (!(str = ft_cat(0, str, f->pr, '0')))
		return (NULL);
	str[f->pr - len] = '0';
	tmp = str;
	tmpchar = ft_chardup(sp->i >= 0 ? ' ' : '-');
	if (!(str = ft_strjoin(tmpchar, str)))
		return (NULL);
	free(tmp);
	free(tmpchar);
	return (str);
}

char	*precision_integer(char *str, t_sp *sp, t_f *f)
{
	if (f->precision)
	{
		if (!sp->i && !f->pr)
		{
			if (!(str = ft_chardup('\0')))
				return (NULL);
		}
		else if (f->space && f->precision && f->pr >= (int)ft_strlen(str))
		{
			if (!(str = ft_sign(str, sp, f)))
				return (NULL);
		}
		else
		{
			if (!(str = ft_cat(0, str, f->pr, '0')))
				return (NULL);
		}
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

char	*ft_integer(va_list arg, t_sp *sp, t_f *f)
{
	char	*str;
	char	*tmp;
	char	*tmpchar;

	sp->i = va_arg(arg, int);
	if (!(str = ft_itoa(sp->i)))
		return (NULL);
	if (sp->i >= 0 && f->space)
	{
		tmp = str;
		tmpchar = ft_chardup(sp->i >= 0 ? ' ' : '-');
		if (!(str = ft_strjoin(tmpchar, str)))
			return (NULL);
		free(tmp);
		free(tmpchar);
	}
	if (!(str = precision_integer(str, sp, f)))
		return (NULL);
	if (!(str = width_integer(str, f)))
		return (NULL);
	return (str);
}
