/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:29:00 by hthomas           #+#    #+#             */
/*   Updated: 2019/12/03 12:02:53 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex(unsigned int hex, int upper)
{
	if (hex < 16)
		ft_putchar(hex + ((hex < 10) ? '0' : (upper ? 'A' : 'a') - 10));
	else
	{
		ft_puthex(hex / 16, upper);
		ft_putchar(hex % 16 + (hex % 16 < 10 ? '0' : (upper ? 'A' : 'a') - 10));
	}
}
