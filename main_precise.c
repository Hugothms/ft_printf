/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_precise.c                                     ::      ::    ::   */
/*                                                    : :         :     */
/*   By: hthomas <hthomas@student.42.fr>            #  :       #        */
/*                                                #####   #           */
/*   Created: 2019/12/15 100:02:50 by hthomas           ##    ##             */
/*   Updated: 2019/12/16 17:07:31 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/ft_printf.h"
#include<stdio.h>
#include<limits.h>

int	main(void)
{
	int ret;
	int ret2;

	//int		c = 'a';
/*
	ret = printf("|%d|", INT_MIN);
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%d|", INT_MIN);
	printf("\n\033[0;36mreturn = %d\033[0m\n\n\n\n", ret2);

	ret = printf("|%d|", -42);
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%d|", -42);
	printf("\n\033[0;36mreturn = %d\033[0m\n\n\n\n\n\n\n", ret2);



	ret = printf("|%5%|");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%5%|");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n", ret2);

	ret = printf("|%.5%|");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%.5%|");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n", ret2);

	ret = printf("|%05%|");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%05%|");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n", ret2);

	ret = printf("|%010.5%|");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%010.5%|");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n", ret2);

	ret = printf("|%10.5%|");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%10.5%|");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n\n\n\n", ret2);
*/
/*
	ret = printf("|%010.5i|", -42);
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%010.5i|", -42);
	printf("\n\033[0;36mreturn = %d\033[0m\n\n", ret2);

	ret = printf("|%10.5i|", -42);
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%10.5i|", -42);
	printf("\n\033[0;36mreturn = %d\033[0m\n\n\n\n\n\n", ret2);

*/

/*
	ret = printf("|%010.5x|", 420);
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%010.5x|", 420);
	printf("\n\033[0;36mreturn = %d\033[0m\n\n", ret2);

	ret = printf("|%10.5x|", 420);
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%10.5x|", 420);
	printf("\n\033[0;36mreturn = %d\033[0m\n\n", ret2);

*/



/*
ret = printf("|%-05%|");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%-05%|");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n", ret2);

	ret = printf("|%-5%|");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%-5%|");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n", ret2);

*/


	ret = printf("|%c|", 0);
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%c|", 0);
	printf("\n\033[0;36mreturn = %d\033[0m\n\n", ret2);

	ret = printf("|%-5c|", 0);
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%-5c|", 0);
	printf("\n\033[0;36mreturn = %d\033[0m\n\n", ret2);


/*
	ret = printf("|%010.4%|\t|%010.4%|\t|%010.4%|\t%s", -5, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%010.4%|\t|%010.4%|\t|%010.4%|\t%s", -5, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n", ret2);

	ret = printf("|%15.i|\t|%15.i|\t|%15.i|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%15.i|\t|%15.i|\t|%15.i|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n", ret2);

	ret = printf("|%2.0i|\t|%2.0i|\t|%2.0i|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%2.0i|\t|%2.0i|\t|%2.0i|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n", ret2);

	ret = printf("|%3.i|\t|%3.i|\t|%3.i|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%3.i|\t|%3.i|\t|%3.i|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n", ret2);

	ret = printf("|%7.5i|\t|%7.5i|\t|%7.5i|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%7.5i|\t|%7.5i|\t|%7.5i|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n", ret2);

	ret = printf("|%2.1i|\t|%2.1i|\t|%2.1i|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%2.1i|\t|%2.1i|\t|%2.1i|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n\n\n\n\n\n", ret2);




	ret = printf("|%03i|\t|%03i|\t|%03i|\t%s", 1, -1, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%03i|\t|%03i|\t|%03i|\t%s", 1, -1, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n", ret2);

	ret = printf("|%010.4%|\t|%010.4%|\t|%010.4%|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%010.4%|\t|%010.4%|\t|%010.4%|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n", ret2);

	ret = printf("|%3.4i|\t|%3.4i|\t|%3.4i|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%3.4i|\t|%3.4i|\t|%3.4i|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n", ret2);

	ret = printf("|%3.3i|\t|%3.3i|\t|%3.3i|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%3.3i|\t|%3.3i|\t|%3.3i|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n", ret2);

	ret = printf("|%3.2i|\t|%3.2i|\t|%3.2i|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%3.2i|\t|%3.2i|\t|%3.2i|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n", ret2);

	ret = printf("|%8.2i|\t|%8.2i|\t|%8.2i|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%8.2i|\t|%8.2i|\t|%8.2i|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n", ret2);

	ret = printf("|%2.1i|\t|%2.1i|\t|%2.1i|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%2.1i|\t|%2.1i|\t|%2.1i|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n", ret2);

	ret = printf("|%.i|\t|%.i|\t|%.i|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%.i|\t|%.i|\t|%.i|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n\n\n\n\n", ret2);





	ret = printf("|%1.i|\t|%1.i|\t|%1.i|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%1.i|\t|%1.i|\t|%1.i|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n", ret2);

	ret = printf("|%.i|\t|%.i|\t|%.i|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%.i|\t|%.i|\t|%.i|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n", ret2);

	ret = printf("|%-1i|\t|%-1i|\t|%-1i|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%-1i|\t|%-1i|\t|%-1i|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n", ret2);

	ret = printf("|%1i|\t|%1i|\t|%1i|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%1i|\t|%1i|\t|%1i|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n", ret2);



	ret = printf("|%1.i|\t|%1.i|\t|%1.i|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%1.i|\t|%1.i|\t|%1.i|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n", ret2);

	ret = printf("|%-1.i|\t|%-1.i|\t|%-1.i|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%-1.i|\t|%-1.i|\t|%-1.i|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n\n\n", ret2);





	ret = printf("|%4.4i|\t|%4.4i|\t|%4.4i|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%4.4i|\t|%4.4i|\t|%4.4i|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n", ret2);

	ret = printf("|%-4.i|\t|%-4.i|\t|%-4.i|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%-4.i|\t|%-4.i|\t|%-4.i|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n", ret2);

	ret = printf("|%.0i|\t|%.0i|\t|%.0i|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%.0i|\t|%.0i|\t|%.0i|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n", ret2);

	ret = printf("|%i|\t|%i|\t|%i|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%i|\t|%i|\t|%i|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n", ret2);

	ret = printf("|%-2.0i|\t|%-2.0i|\t|%-2.0i|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%-2.0i|\t|%-2.0i|\t|%-2.0i|\t%s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n", ret2);

	ret = printf("|%.1i|\t|%.1i|\t|%.1i| %s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%.1i|\t|%.1i|\t|%.1i| %s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n", ret2);

	ret = printf("|%.1i|\t|%.1i|\t|%.1i| %s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%.1i|\t|%.1i|\t|%.1i| %s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n", ret2);

	ret = printf("|%-100.4i|\t|%-100.4i|\t|%-100.4i| %s", 138, -138, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%-100.4i|\t|%-100.4i|\t|%-100.4i| %s", 138, -138, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n\n\n", ret2);



	ret = printf("|%-.4u| |%-4.4u| |%-4.4u| %s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%-4.4u| |%-4.4u| |%-4.4u| %s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n", ret2);

	ret = printf("|%-4.4x| |%-4.4x| |%-4.4x| %s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%-4.4x| |%-4.4x| |%-4.4x| %s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n", ret2);

	ret = printf("|%-4.4X| |%-4.4X| |%-4.4X| %s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%-4.4X| |%-4.4X| |%-4.4X| %s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n", ret2);

	ret = printf("|%-4p| %s", &c, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%-4p| %s", &c, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n", ret2);

	ret = printf("|%-4c| |%-4c| |%-4c| %s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%-4c| |%-4c| |%-4c| %s", 100, -100, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n", ret2);

	ret = printf("|%%| %s", "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%%| %s", "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n", ret2);

	ret = printf("|%s| |%s| |%s| %s", "Hello world-\\ok", "", NULL, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%s| |%s| |%s| %s", "Hello world-\\ok", "", NULL, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n", ret2);
*/
	//system("leaks precise.out");
	return (0);
}
