/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:40:45 by hthomas           #+#    #+#             */
/*   Updated: 2019/12/01 18:53:23 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(int argc, char const *argv[])
{
	// ! Char
	ft_printf("\n");
	ft_printf("###############   CHAR   ###############\n");
	ft_printf("A char: %s\n", "Hugo");
	char c = 32;
	while (c < 127)
		ft_printf("%c", c++);
	ft_printf("\n");

	// ! String
	ft_printf("\n");
	ft_printf("###############  STRING  ###############\n");
	ft_printf("Hello World!\n");
	ft_printf("A string: %s\n", "Hugo");
	char *bro = "Reda";
	ft_printf("Two strings: %s and %s\n", "Enzo", bro);

	// ! Integer
	ft_printf("\n");
	ft_printf("###############  INTEGER ###############\n");
	ft_printf("An integer: %d\n", -32);
	ft_printf("Zero: %d\n", 0);
	ft_printf("Min integer: %d\n", INT_MIN);
	ft_printf("Max integer: %d\n", INT_MAX);
	int d = 31, m = 8, y = 1996;
	ft_printf("I am born the: %d/%d/%d\n", d, m, y);

	// ! Unsigned integer
	ft_printf("\n");
	ft_printf("############### UNSIGNED ###############\n");
	ft_printf("An unsigned integer: %u\n", 32);
	ft_printf("Zero: %u\n", 0);
	ft_printf("Max unsigned integer: %u\n", UINT_MAX);
	unsigned int ud = 31, um = 8, uy = 1996;
	ft_printf("I am born the: %u/%u/%u\n", ud, um, uy);
	return (0);
}
