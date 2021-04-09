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

void			ft_get_blanklen(t_op *op, int arglen, t_arg *arg)
{
	if (arg->c || arg->p || arg->per)
		ft_case_cpper(op, arglen);
	else if (arg->s)
		ft_case_str(op, arglen);
	else if (arg->d || arg->i || arg->u || arg->x || arg->bigx)
	{
		if (op->p_ast == 1 && op->precision < 0)
			op->precision = 0;
		op->big[0] = ft_get_max(arglen, op->precision);
		if (op->big[0] == 0)
			ft_case_arglenbig(op, arglen);
		else
			ft_case_precisionbig(op, arglen);
	}
	if (op->blank < 0)
		op->blank = 0;
	if (op->zerolen < 0)
		op->zerolen = 0;
	op->total += (op->blank + op->zerolen);
}

int				ft_get_nbrlen(ssize_t nb, t_op *op)
{
	int			len;

	len = 0;
	if (nb == 0)
	{
		op->total += 1;
		return (1);
	}
	if (nb < 0)
	{
		op->miner = 1;
		nb *= -1;
		op->total += 1;
	}
	while (nb)
	{
		nb /= 10;
		len++;
	}
	op->total += len;
	return (len);
}
