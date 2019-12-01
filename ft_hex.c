/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:49:15 by hthomas           #+#    #+#             */
/*   Updated: 2019/12/01 19:01:34 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_hex(const char *format, va_list arg, t_sp sp)
{
	sp.p = va_arg(arg, long long);
	ft_puthex(sp.p);
	sp.len += ft_count_len_hex(sp.p);
}
