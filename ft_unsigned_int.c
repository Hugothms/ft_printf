/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:49:15 by hthomas           #+#    #+#             */
/*   Updated: 2019/12/01 18:37:31 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_unsigned_int(const char *format, va_list arg, t_sp sp)
{
	sp.u = va_arg(arg, unsigned int);
	ft_putnbr_unsigned(sp.u);
	sp.len += ft_count_len_nbr(sp.u);
}

