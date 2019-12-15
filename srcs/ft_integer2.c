/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:49:15 by hthomas           #+#    #+#             */
/*   Updated: 2019/12/15 11:33:49 by hthomas          ###   ########.fr       */
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

char *precision_integer(char *str, t_sp *sp, t_f *f)
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

char	*keep_position_sign(char *str, t_f *f)
{
	int		index_sign;
	int		index_first;
	int		foundsign;
	int		foundfirst;
	char	c;

	index_sign = f->minus ? 0 : ft_strlen(str);
	index_first = 0;
	while (index_first < (int)ft_strlen(str) && !(foundfirst = in_charset(str[index_first], "+-0")))
		index_first++;
	while ((f->minus ? index_sign < (int)ft_strlen(str) : index_sign) && !(foundsign = in_charset(str[index_sign], " +-")))
		f->minus ? index_sign++ : index_sign--;
	if (!foundfirst)
	{
		while (index_first < index_sign && !in_charset(str[index_first], " "))
			index_first++;
	}
	if (foundsign && foundfirst)
	{
		c = str[index_sign];
		str[index_sign] = str[index_first];
		str[index_first] = c;
	}
	return (str);
}
