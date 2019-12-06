/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_precise.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:40:45 by hthomas           #+#    #+#             */
/*   Updated: 2019/12/06 16:50:15 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include<stdio.h>
int	main(void)
{
	int ret;
	int ret2;
	int count;
	int countf;
	void	*ptr2 = "ok";
	void	*ptr3 = NULL;
	int	c;

	printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^TEST 23\n");
	ret = printf("%.1s\n", ptr3);
	printf("\n\033[0;36mExpected return =\t%d ! \033[0m\n", ret);
	ret2 = ft_printf("%.1s\n", ptr3);
	printf("\n\033[0;36mYour return =\t\t%d ! \033[0m\n", ret2);
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
