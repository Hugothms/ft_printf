/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:40:45 by hthomas           #+#    #+#             */
/*   Updated: 2019/12/05 18:05:06 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include<stdio.h>
int	main(void)
{

	// ! Char
	ft_printf("\n\n");
	ft_printf("##############################   CHAR   ##############################\n");
	char c = 32;
	ft_printf("A char: %c\n", 'A');
	while (c < 127)
	{
		//ft_printf("%c\t", c);
		////printf("%c\t", c);
		c++;
	}
	ft_printf("\n");

	// ! String
	ft_printf("\n\n");
	ft_printf("##############################  STRING  ##############################\n");
	ft_printf("A string: %s\n", "Hugo");
	printf("A string: %s\n", "Hugo");
	char *bro = "Reda";
	ft_printf("Two strings: %s and %s\n", "Enzo", bro);
	printf("Two strings: %s and %s\n", "Enzo", bro);

	// ! Integer
	ft_printf("\n\n");
	ft_printf("############################## INTEGER  ##############################\n");
	ft_printf("An integer: %d\n", -32);
	printf("An integer: %d\n", -32);
	ft_printf("Zero: %d\n", 0);
	printf("Zero: %d\n", 0);
	ft_printf("Min integer: %d\n", INT_MIN);
	printf("Min integer: %d\n", INT_MIN);
	ft_printf("Max integer: %d\n", INT_MAX);
	printf("Max integer: %d\n", INT_MAX);
	int d = 31, m = 8, y = 1996;
	ft_printf("I am born the: |%02d/%02d/%04d|\n", d, m, y);
	printf("I am born the: |%02d/%02d/%04d|\n", d, m, y);
	ft_printf("I will die: \t|%-4d/%-4d/%-4d|\n", d, m, y + 100);
	printf("I will die: \t|%-4d/%-4d/%-4d|\n", d, m, y + 100);
	ft_printf("|%-42d|\n", 42);
	printf("|%-42d|\n", 42);

	// ! Unsigned integer
	ft_printf("\n\n");
	ft_printf("############################## UNSIGNED ##############################\n");
	ft_printf("An unsigned integer: %u\n", 32);
	printf("An unsigned integer: %u\n", 32);
	ft_printf("Zero: %u\n", 0);
	printf("Zero: %u\n", 0);
	ft_printf("Max unsigned integer: %u\n", UINT_MAX);
	printf("Max unsigned integer: %u\n", UINT_MAX);
	unsigned int ud = 31, um = 8, uy = 1996;
	ft_printf("I am born the: %u/%u/%u\n", ud, um, uy);
	printf("I am born the: %u/%u/%u\n", ud, um, uy);

	// ! Pointer
	ft_printf("\n\n");
	ft_printf("############################## POINTER  ##############################\n");
	ft_printf("Null pointer: %p\n", NULL);
	printf("Null pointer: %p\n", NULL);
	void *pointer = &c;
	ft_printf("A pointer: %p\n", pointer);
	printf("A pointer: %p\n", pointer);


	// ! Hex lower case
	ft_printf("\n\n");
	ft_printf("############################# HEX lower  #############################\n");
	ft_printf("An address: %x\n", 0x00f4);
	printf("An address: %x\n", 0x00f4);
	ft_printf("Null pointer: %x\n", 0);
	printf("Null pointer: %x\n", 0);
	ft_printf("Max long long: %x\n", UINT_MAX);
	printf("Max long long: %x\n", UINT_MAX);
	long long hex = 0;
	while (hex <= 0xFF)
	{
		//ft_printf("%x\t", hex);
		////printf("%x\t", hex);
		hex++;
	}


	// ! Hex upper case
	ft_printf("\n\n");
	ft_printf("############################# HEX upper  #############################\n");
	ft_printf("An address: %X\n", 0x00f4);
	printf("An address: %X\n", 0x00f4);
	ft_printf("Null pointer: %X\n", 0);
	printf("Null pointer: %X\n", 0);
	ft_printf("Max long long: %X\n", UINT_MAX);
	printf("Max long long: %X\n", UINT_MAX);
	hex = 0;
	while (hex <= 0xFF)
	{
		//ft_printf("%X\t", hex);
		////printf("%X\t", hex);
		hex++;
	}

	// ! Tests
	ft_printf("\n\n");
	ft_printf("################# COMBINATION FLAGS-WIDTH-PRECISION  #################\n");
	// printf("\t\t05.8d\n");
	printf("|%05.8d|\n", 420);
	ft_printf("|%05.8d|\n\n", 420);
	// printf("\t\t0.8d\n");
	printf("|%0.8d|\n", 420);
	ft_printf("|%0.8d|\n\n", 420);
	// printf("\t\t08.5d\n");
	printf("|%08.5d|\n", 420);
	ft_printf("|%08.5d|\n\n", 420);
	// printf("\t\t-5.8d\n");
	printf("|%-5.8d|\n", 420);
	ft_printf("|%-5.8d|\n\n", 420);
	// printf("\t\t-8.5d\n");
	printf("|%-8.5d|\n", 420);
	ft_printf("|%-8.5d|\n\n", 420);
	// printf("\t\t05.8d\n");
	printf("|%0*.8d|\n", 5, 420);
	ft_printf("|%0*.8d|\n\n", 5, 420);

	return (0);
}

//For integer specifiers (d, i, o, u, x, X): precision specifies
//the minimum number of digits to be written.
//If the value to be written is shorter than this number,
//the result is padded with leading zeros.
//The value is not truncated even if the result is longer.
//A precision of 0 means that no character is written for the value 0.

// p doit afficher les zero avant
// x et X ne prennent que 8 bits

// * CONVERSIONS:	c	s	p	d	i	u	x	X	%
// * ANY COMB:		[-0number][.number]	'*'
// * F. AUTORISÉES:	malloc, free, write, va_start, va_arg, va_copy, va_end
