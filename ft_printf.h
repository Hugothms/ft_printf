/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:44:08 by hthomas           #+#    #+#             */
/*   Updated: 2019/12/04 16:37:25 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>

typedef struct		s_printf
{
	int				index;
	int				len;
	int				i;
	unsigned int	u;
	char			*s;
	long long		p;
	unsigned int	h;
}					t_sp;

typedef struct		s_flags
{
	int				zb;
	int				za;
	int				width;
	int				pr;
}					t_f;

int				ft_printf(const char *format, ...);

char			ft_char(va_list arg, t_sp *sp);
char			ft_string(va_list arg, t_sp *sp);
char			ft_pointer(va_list arg, t_sp *sp);
char			ft_integer(va_list arg, t_sp *sp);
char			ft_unsigned_int(va_list arg, t_sp *sp);
char			ft_hex(va_list arg, t_sp *sp);

t_sp			*init_sp(void);
t_sp			*reset_sp(t_sp *sp);
void			free_sp(t_sp *sp);
t_f				*init_f(void);

void			ft_put_zeros(int size, t_sp *sp, int len);
void			ft_put_spaces(int width, t_sp *sp, int len);

int				ft_atoi_no_sign(const char *nptr);
void			ft_get_flags(const char *fmt, t_sp *sp, t_f	*f);
void			ft_get_width(const char *fmt, t_sp *sp, t_f	*f);
void			ft_get_precision(const char *fmt, t_sp *sp, t_f	*f);

#endif
