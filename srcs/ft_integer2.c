/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:49:15 by hthomas           #+#    #+#             */
/*   Updated: 2019/12/13 17:15:42 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_add_sign(char *str, t_sp *sp, t_f *f)
{
	char	*tmp;
	char	*tmpchar;
	char	sign;

	if (sp->i >= 0 && (f->space || f->plus))
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
	int		condition;

	len = ft_strlen(str);
	if (!sp->i && !f->pr)
	{
		if (!(str = precision_sign(str, f)))
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
	while (ifirst < isign && !(foundfirst = in_charset(str[ifirst], "0+-")))
		ifirst++;
	while (isign && !(foundsign = in_charset(str[isign], " +-")))
		isign--;
	if (!foundfirst)
	{
		while (ifirst < isign && !in_charset(str[ifirst], " "))
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
