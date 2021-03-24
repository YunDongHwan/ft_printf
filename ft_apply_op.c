/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 03:31:56 by doyun             #+#    #+#             */
/*   Updated: 2021/03/17 06:28:03 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_apply_char(va_list ap, t_op *op)
{
	char		c;

	c = va_arg(ap, int);
	ft_get_blanklen(op, 1);
//	printf("in apply char\n");
	if (op->sign == 0)
	{
		ft_putblank(op->blank);
//		printf("putblank ok\n");
	}
	ft_putchar_fd(c, 1);
	if(op->sign == 1)
	{
		ft_putblank(op->blank);
//		printf("putblank ok\n");
	}
}


int			ft_apply_option(va_list ap, t_op *op, t_arg *arg)
{
//	printf("%d\n", arg->c);
    if (arg->c == 1)
	{
		ft_apply_char(ap, op);
//		printf("apply char ok\n");
		return (1);
	}
	return (0);
}
