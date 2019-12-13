/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_precise.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:40:45 by hthomas           #+#    #+#             */
/*   Updated: 2019/12/13 18:42:49 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include<stdio.h>
#include<limits.h>

int	main(void)
{
	// int ret;
	// int ret2;
	// int count=0;
	// int countf=0;
	// void	*ptr2 = "ok";
	// void	*ptr3 = NULL;
	//int		c = 'a';
/*
	ret = printf("|%-20d| %s", -742000710, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%-20d| %s", -742000710, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n\n", ret2);
*/

	ft_printf("%cj", '\0');
	ft_printf("%c%08.4u", '\0', 2147483647);
	ft_printf("%-20.0u%-*.5X%-c8Fxr%-uUUI%%", 0, -4, 2147483647, '\0', 2147483647);
	ft_printf("5aRoqv%0XyU%*cynUt%*i4N6u%u", -2147483647, 0, '\0', -6, 0, 0);
	ft_printf("%c", '\0');
	ft_printf("%0.2d%-cm%-u%9.*sBkHmb", 0, '\0', -2147483647, -6, "lDaWvaviJNcjAuyGUkmRA8HqddXJ FNjj6Jqs88sMvX 36RawdaGeNU2PlSz");
	ft_printf("e%.4sMG %3i5yTR%5c%*c%%", "", 363576202, '\0', -2, '\0');
	ft_printf("0nv%9c%%3USoqzY%-.2dzVQP7", '\0', 2147483647);
	ft_printf("%-1.3xDe7ZTE%*XsM5v%19c%-16.4XKUrI", -2147483647, -5, -2147483647, '\0', -2147483647);
	ft_printf("xP4Uk%-2.5uFr%-i%-19cjCoik%%4P", -2147483647, 2147483647, '\0');
	ft_printf("%%r%-18c5Nk9W7KA%11.*X3lhU%sAw9%-s", '\0', 7, -626467661, "", NULL);
	ft_printf("%11.3d%c", 2147483647, '\0');
	ft_printf("%cUmqU%*iFejcnlHadVuG%d%i%.0i", '\0', 3, -2147483647, 0, 924297406, 2147483647);

/*
	ret = printf("|%#i| |%#i| |%#i| %s", 42, -42, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%#i| |%#i| |%#i| %s", 42, -42, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n\n", ret2);

	ret = printf("|%#d| |%#d| |%#d| %s", 42, -42, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%#d| |%#d| |%#d| %s", 42, -42, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n\n", ret2);

	ret = printf("|%#u| |%#u| |%#u| %s", 42, -42, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%#u| |%#u| |%#u| %s", 42, -42, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n\n", ret2);

	ret = printf("|%#x| |%#x| |%#x| %s", 42, -42, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%#x| |%#x| |%#x| %s", 42, -42, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n\n", ret2);

	ret = printf("|%#X| |%#X| |%#X| %s", 42, -42, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%#X| |%#X| |%#X| %s", 42, -42, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n\n", ret2);

	ret = printf("|%#p| %s", &c, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%#p| %s", &c, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n\n", ret2);

	ret = printf("|%#c| |%#c| |%#c| %s", 42, -42, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%#c| |%#c| |%#c| %s", 42, -42, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n\n", ret2);

	ret = printf("|%%| %s", "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%%| %s", "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n\n", ret2);

	ret = printf("|%s| |%s| |%s| %s", "Hello world+-\\ok", "", NULL, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%s| |%s| |%s| %s", "Hello world+-\\ok", "", NULL, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n\n", ret2);
*/
	// if (ret == ret2)
	// {
	// 	printf("\033[0;42m               OK :) \033[0m\n");
	// 	count++;
	// 	countf++;
	// }
	// else
	// 	printf("\033[0;41m               KO :( \033[0m\n");
	system("leaks precise.out");
	return (0);
}
