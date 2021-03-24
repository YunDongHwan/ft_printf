/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getlenth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 06:51:02 by doyun             #+#    #+#             */
/*   Updated: 2021/03/17 02:11:45 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_get_blanklen(t_op *op, int arglen)
{
	op->blank = op->width - ft_get_max(op->precision, arglen);	
	if (op->blank <= 0)
		op->blank = 0;
//	printf("op->blank : %d\n", op->blank);
//	printf("op->width : %d\n", op->width);
//	printf("op->precision : %d\n", op->precision);
//	printf("arglen : %d\n", arglen);
}

int			ft_get_signlen(t_op *op)
{
	if (op->sign)
		return (1);
	return (0);
}
