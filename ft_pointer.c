/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:49:15 by hthomas           #+#    #+#             */
/*   Updated: 2019/12/01 18:34:40 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_pointer(const char *format, va_list arg, t_sp sp)
{
	sp.p = va_arg(arg, long long);
}
