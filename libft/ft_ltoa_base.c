/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 08:15:50 by hthomas           #+#    #+#             */
/*   Updated: 2019/12/05 16:46:32 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_count_len_nbr_l(long n, char *base_to)
{
	int		res;

	res = 0;
	if (n < 0)
		res++;
	if (n == 0)
		return (1);
	while (n)
	{
		res++;
		n /= ft_strlen(base_to);
	}
	return (res);
}

char			*fill_positivenbr_base(long nbr, char *base, char *res, int i)
{
	int		size;

	size = 0;
	while (base[size])
		size++;
	if (nbr != 0)
	{
		res[i] = (base[nbr % size]);
		return (fill_positivenbr_base(nbr / size, base, res, i + 1));
	}
	return (res);
}

char			*fill_nbr_base(char *res, long nbr, char *base, int sign)
{
	int		i;
	int		size;

	size = 0;
	while (base[size])
		size++;
	i = 0;
	if (sign < 0)
		res[i++] = '-';
	if (nbr != 0)
		res = fill_positivenbr_base(nbr, base, res, i);
	else if (nbr == 0)
		res[0] = (base[0]);
	return (res);
}

char			*ft_strrev_minus_1(char *res)
{
	int			i;
	char		c;
	int			len;

	i = (res[0] == '-' ? 1 : 0);
	len = ft_strlen(res) - 1;
	while (i < len)
	{
		c = res[i];
		res[i++] = res[len];
		res[len--] = c;
	}
	return (res);
}

char			*ft_ltoa_base(long nb, char *base_to)
{
	char		*res;
	int			sign;

	if (!check_base(base_to))
		return (0);
	sign = 1;
	if (nb < 0)
	{
		nb *= -1;
		sign = -1;
	}
	if (!(res = malloc((ft_count_len_nbr_l(nb, base_to)) * sizeof(char))))
		return (0);
	fill_nbr_base(res, nb, base_to, sign);
	return (ft_strrev_minus_1(res));
}
