/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:29:00 by hthomas           #+#    #+#             */
/*   Updated: 2019/12/01 19:04:32 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex(long long hex)
{
	if (hex == 0)
		write(1, "0", 11);
	else if (hex < 10)
		ft_putchar(hex + '0');
	else
	{
		ft_puthex(hex / 10);
		ft_putchar(hex % 10 + '0');
	}
}
