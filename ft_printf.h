/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:44:08 by hthomas           #+#    #+#             */
/*   Updated: 2019/12/03 15:35:39 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>

typedef struct	s_printf
{
	int				index;
	int				len;
	int				i;
	unsigned int	u;
	char			*s;
	long long		p;
	unsigned int	h;
}				t_sp;

typedef struct	s_flags
{
	char			flag;
	int				size;
}				t_f;

int				ft_printf(const char *format, ...);

void			ft_char(const char *format, va_list arg, t_sp *sp);
void			ft_string(const char *format, va_list arg, t_sp *sp);
void			ft_pointer(const char *format, va_list arg, t_sp *sp);
void			ft_integer(const char *format, va_list arg, t_sp *sp);
void			ft_unsigned_int(const char *format, va_list arg, t_sp *sp);
void			ft_hex(const char *format, va_list arg, t_sp *sp, int upper);

t_sp			*init_sp(void);
t_sp			*reset_sp(t_sp *sp);
void			free_sp(t_sp *sp);

void			ft_put_zeros(int size, t_sp *sp);

#endif
