/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:49:15 by hthomas           #+#    #+#             */
/*   Updated: 2019/12/06 14:45:27 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_pointer(va_list arg, t_sp *sp)
{
	char	*bl;

	bl = "0123456789abcdef";
	sp->p = va_arg(arg, long);
	sp->len += ft_count_len_hex(sp->p) + 2;
	return (ft_strjoin(ft_strdup("0x"), ft_ltoa_base(sp->p, bl)));
}
