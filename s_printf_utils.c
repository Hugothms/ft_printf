/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_printf_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 20:25:55 by hthomas           #+#    #+#             */
/*   Updated: 2019/12/01 15:31:59 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_sp*	init_sp(void)
{
	t_sp	*sp;

	if (!(sp = (t_sp*)malloc(sizeof(t_sp))))
		return (NULL);
	sp->index = 0;
	sp->len = 0;
	sp->d = 0;
	sp->u = 0;
	sp->s = NULL;
	sp->p = 0;
	return (sp);
}

t_sp	*reset_sp(t_sp *sp)
{
	sp->d = 0;
	sp->u = 0;
	if (sp->s)
		free(sp->s);
	sp->s = NULL;
	sp->p = 0;
	return (sp);
}

void	free_sp(t_sp *sp)
{
	if(sp->s)
		free(sp->s);
	free(sp);
}
