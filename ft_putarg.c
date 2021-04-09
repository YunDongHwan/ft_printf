/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 02:12:42 by doyun             #+#    #+#             */
/*   Updated: 2021/03/17 03:21:20 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putblank(t_op *op)
{	
	while (op->blank > 0)
	{
		ft_putchar_fd(' ', 1);
		op->blank--;		
	}

}

void		ft_putzero(t_op *op)
{		
	while (op->zerolen > 0)
	{		
		ft_putchar_fd('0', 1);
		op->zerolen--;		
	}
}

void		ft_reset_op(t_op *op, t_arg *arg)
{
	op->chk = 0;
	op->sign = 0;
	op->miner = 0;
	op->zero = 0;
	op->zerolen = 0;
	op->width = 0;
	op->precision = 0;
	op->p_ast = 0;
	op->blank = 0;	
	op->dot = 0;
	op->nodot = 0;
	arg->c = 0;
	arg->s = 0;
	arg->p = 0;
	arg->d = 0;
	arg->i = 0;
	arg->u = 0;
	arg->x = 0;
	arg->X = 0;
	arg->per = 0;
}