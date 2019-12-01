/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:49:15 by hthomas           #+#    #+#             */
/*   Updated: 2019/12/01 18:34:53 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_integer(const char *format, va_list arg, t_sp sp)
{
	sp.d = va_arg(arg, int);
	ft_putnbr(sp.d);
	sp.len += ft_count_len_nbr(sp.d);
}
