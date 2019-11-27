/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:42:33 by hthomas           #+#    #+#             */
/*   Updated: 2019/11/27 18:36:31 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		done;

	va_start(args, format);
	done = vfprintf(stdout, format, args);
	// TODO write code here

	va_end(args);
	return (done);
}




// * malloc, free, write, va_start, va_arg, va_copy, va_end
