/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:49:15 by hthomas           #+#    #+#             */
/*   Updated: 2019/12/06 14:43:30 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hex(va_list arg, t_sp *sp, int uppercase)
{
	char	*bl;

	bl = "0123456789abcdef";
	sp->h = va_arg(arg, unsigned int);
	sp->len += ft_count_len_hex(sp->h);
	return (ft_uitoa_base(sp->h, uppercase ? bl : "0123456789ABCDEF"));
}
