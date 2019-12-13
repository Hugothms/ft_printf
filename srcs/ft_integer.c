/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:49:15 by hthomas           #+#    #+#             */
/*   Updated: 2019/12/13 14:35:16 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_add_sign(char *str, t_sp *sp, t_f *f)
{
	char	*tmp;
	char	*tmpchar;
	char	positivesign;

	positivesign = f->space ? ' ' : '+';
	if (sp->i >= 0 && (f->space || f->plus))
	{
		tmp = str;
		if (!(tmpchar = ft_chardup(sp->i >= 0 ? positivesign : '-')))
			return (NULL);
		if (!(str = ft_strjoin(tmpchar, str)))
			return (NULL);
		free(tmp);
		free(tmpchar);
	}
	return (str);
}

char	*precision_integer(char *str, t_sp *sp, t_f *f)
{
	int		len;
	int		condition;

	len = ft_strlen(str);
	if (!sp->i && !f->pr)
	{
		free(str);
		if (!(str = ft_chardup('\0')))
			return (NULL);
	}
	else if (f->precision && f->pr >= len)
	{
		condition = sp->i < 0 || f->plus || f->space;
		if (!(str = ft_cat(0, str, f->pr + condition, '0')))
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
	int		isign;
	int		ifirst;
	char	c;
	int		foundsign;
	int		foundfirst;

	isign = ft_strlen(str);
	ifirst = 0;
	while (!(foundsign = in_charset(str[isign], " +-")))
		isign--;
	while (!(foundfirst = in_charset(str[ifirst], "0+-")))
		ifirst++;
	if (!ifirst)
	{
		while (!in_charset(str[ifirst], " "))
			ifirst++;
	}
	if (foundsign && foundfirst)
	{
		c = str[isign];
		str[isign] = str[ifirst];
		str[ifirst] = c;
	}
	return (str);
}

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
	if (sp->i < 0 || f->plus || f->space)
	{
		if (!(str = keep_position_sign(str)))
			return (NULL);
	}
	return (str);
}
