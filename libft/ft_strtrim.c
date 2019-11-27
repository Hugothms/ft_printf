/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:30:13 by hthomas           #+#    #+#             */
/*   Updated: 2019/11/06 16:30:14 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_charset(char c, char const *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i++])
			return (1);
	}
	return (0);
}

static int	count_size(char const *s1, char const *set)
{
	int	blanks;
	int	i;

	if (!*s1)
		return (0);
	blanks = 0;
	i = 0;
	while (in_charset(s1[i++], set))
		blanks++;
	if (!(ft_strlen(s1) - blanks))
		return (0);
	i = ft_strlen(s1) - 1;
	while (in_charset(s1[i--], set))
		blanks++;
	return (ft_strlen(s1) - blanks);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		size;
	char	*new;

	if (!s1)
		return (NULL);
	size = count_size(s1, set);
	if (!(new = malloc((size + 1) * sizeof(char))))
		return (NULL);
	if (!size)
	{
		*new = '\0';
		return (new);
	}
	start = 0;
	while (in_charset(s1[start], set))
		start++;
	i = -1;
	while (++i < size)
		new[i] = s1[start + i];
	new[i] = '\0';
	return (new);
}
