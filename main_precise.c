/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_precise.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:40:45 by hthomas           #+#    #+#             */
/*   Updated: 2019/12/06 15:16:25 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include<stdio.h>
int	main(void)
{
	int count = 0;
	int countf = 0;
	int ret = 0;
	int ret2 = 0;

	ret = printf("|Plusieurs nombres %u %u|", -42, -2147483647);
	count = 0;
	printf("\n\033[0;36mExpected return =\t%d ! \033[0m\n", ret);
	ret2 = ft_printf("|Plusieurs nombres %u %u|", -42, -2147483647);
	printf("\n\033[0;36mYour return =\t\t%d ! \033[0m\n", ret2);
	count = 0;
	if (ret == ret2)
	{
		printf("\033[0;42m               OK :) \033[0m\n");
		count++;
		countf++;
	}
	else
		printf("\033[0;41m               KO :( \033[0m\n");


	return (0);
}
