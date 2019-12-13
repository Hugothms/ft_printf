/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_precise.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:40:45 by hthomas           #+#    #+#             */
/*   Updated: 2019/12/13 17:52:51 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include<stdio.h>
#include<limits.h>

int	main(void)
{
	int ret;
	int ret2;
	// int count=0;
	// int countf=0;
	// void	*ptr2 = "ok";
	// void	*ptr3 = NULL;
	int		c = 'a';

	ret = printf("|%i| |%i| |%i| %s", 42, -42, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%i| |%i| |%i| %s", 42, -42, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n\n", ret2);

	ret = printf("|%d| |%d| |%d| %s", 42, -42, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%d| |%d| |%d| %s", 42, -42, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n\n", ret2);

	ret = printf("|%u| |%u| |%u| %s", 42, -42, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%u| |%u| |%u| %s", 42, -42, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n\n", ret2);

	ret = printf("|%x| |%x| |%x| %s", 42, -42, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%x| |%x| |%x| %s", 42, -42, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n\n", ret2);

	ret = printf("|%X| |%X| |%X| %s", 42, -42, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%X| |%X| |%X| %s", 42, -42, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n\n", ret2);

	ret = printf("|%p| %s", &c, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%p| %s", &c, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n\n", ret2);

	ret = printf("|%c| |%c| |%c| %s", 42, -42, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%c| |%c| |%c| %s", 42, -42, 0, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n\n", ret2);

	ret = printf("|%%| %s", "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%%| %s", "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n\n", ret2);

	ret = printf("|%s| |%s| |%s| %s", "Hello world+-\\ok", "", NULL, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n", ret);
	ret2 = ft_printf("|%s| |%s| |%s| %s", "Hello world+-\\ok", "", NULL, "\xF0\x9F\x98\x8D \xF0\x9F\x99\x88 \xF0\x9F\x92\x96 \xF0\x9F\x8C\x9F \xE2\x9C\x85");
	printf("\n\033[0;36mreturn = %d\033[0m\n\n\n", ret2);

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
