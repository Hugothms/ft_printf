/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:42:33 by hthomas           #+#    #+#             */
/*   Updated: 2019/12/03 16:11:28 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include<stdio.h>

char	ft_conversion(const char *fmt, va_list arg, t_sp *sp)
{
	// int	len;

	// len = sp->len;
	sp->index++;
	if (fmt[sp->index] == 'c')
		ft_char(fmt, arg, sp);
	else if (fmt[sp->index] == 's')
		ft_string(fmt, arg, sp);
	else if (fmt[sp->index] == 'p')
		ft_pointer(fmt, arg, sp);
	else if (fmt[sp->index] == 'd' || fmt[sp->index] == 'i')
		ft_integer(fmt, arg, sp);
	else if (fmt[sp->index] == 'u')
		ft_unsigned_int(fmt, arg, sp);
	else if (fmt[sp->index] == 'x')
		ft_hex(fmt, arg, sp, 0);
	else if (fmt[sp->index] == 'X')
		ft_hex(fmt, arg, sp, 1);
	else if (fmt[sp->index] == '%')
	{
		sp->i = '%';
		sp->len++;
	}
	if (in_charset(fmt[sp->index], "cspdiuxX%"))
		return (fmt[sp->index]);
	return (0);
	// return (sp->len - len);
}

void	ft_show(t_sp *sp, char type)
{
	if (type == 'c')
		ft_putchar(sp->i);
	else if (type == 's')
		ft_putstr(sp->s);
	else if (type == 'p')
	{
		ft_putstr("0x");
		ft_putpointer(sp->p);
	}
	else if (type == 'd' || type == 'i')
		ft_putnbr(sp->i);
	else if (type == 'u')
		ft_putnbr_unsigned(sp->u);
	else if (type == 'x')
		ft_puthex(sp->h, 0);
	else if (type == 'X')
		ft_puthex(sp->h, 1);
	else if (type == '%')
		ft_putchar(sp->i);
}

t_f	ft_get_flags(const char *fmt, t_sp *sp)
{
	t_f	sf;

	sf.flag = 0;
	while (!in_charset(fmt[sp->index], "cspdiuxX%"))
	//while (!in_charset(fmt[sp->index], "-0.*"))
	{
		if (fmt[sp->index] == '-' && !sf.flag)
			sf.flag = '-';
		else if (fmt[sp->index] == '0' && !sf.flag)
			sf.flag = '0';
		sp->index++;
	}
	return (sf);
}

int		ft_printf_continue(const char *fmt, va_list arg, t_sp *sp)
{
	t_f		sf;
	char	type;

	printf("\n|%s|\n", &fmt[sp->index]);
	sf = ft_get_flags(fmt, sp);
	type = ft_conversion(fmt, arg, sp);
	sf.size = ft_atoi(&fmt[sp->index]);
	printf("\nflag:%c\n", sf.flag);
	printf("\n|%s|\n", &fmt[sp->index]);
	while (ft_issign(fmt[sp->index]) || ft_isdigit(fmt[sp->index]))
		sp->index++;
	printf("\n|%s|\n", &fmt[sp->index]);
	if (sf.flag == '0')
	{
		printf("on est la");
		ft_put_zeros(sf.size, sp);
	}
	printf("ok");
	ft_show(sp, type);
	if (sf.flag == '-')
	{
		printf("on est ici");
		ft_put_zeros(sf.size, sp);
	}
	return (0);
}

int		ft_printf(const char *fmt, ...)
{
	va_list	arg;
	t_sp	*sp;
	int 	len;

	va_start(arg, fmt);
	if(!(sp = init_sp()))
		return (-1);
	while (fmt[sp->index])
	{
		reset_sp(sp);
		if (fmt[sp->index] == '%')
			ft_printf_continue(fmt, arg, sp);
		else
		{
			ft_putchar(fmt[sp->index]);
			sp->len++;
		}
		sp->index++;
	}
	len = sp->len;
	free_sp(sp);
	va_end(arg);
	return (len);
}
