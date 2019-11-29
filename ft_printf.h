/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:44:08 by hthomas           #+#    #+#             */
/*   Updated: 2019/11/29 18:09:50 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct	s_printf
{
	int				index;
	int				len;
	int				d;
	unsigned int	u;
	char			c;
	char			*s;
	long long		p;
}				t_sp;

int				ft_printf(const char *format, ...);

#endif
