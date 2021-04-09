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

void		ft_get_blanklen(t_op *op, int arglen, t_arg *arg)
{		
	if (arg->c ||  arg->p || arg->per)
	{
		ft_case_cpper(op, arglen);
		// op->blank = op->width - arglen;
		// if (op->zero == 1 && op->sign == 0)
		// {
		// 	op->zerolen = op->blank;
		// 	op->blank = 0;
		// }
	}
	else if(arg->s)
	{
		ft_case_str(op, arglen);
		// op->blank = op->width - arglen;
		// if (op->precision < arglen && op->precision > 0)
		// 	op->blank += (arglen - op->precision);
	}	
	else if (arg->d || arg->i || arg->u || arg->x || arg->X)
	{
		if (op->p_ast == 1 && op->precision < 0) //precision < 0 일때 * 로 받으면 0precion 무시
			op->precision = 0;
		op->big[0]	= ft_get_max(arglen, op->precision);
		if (op->big[0] == 0)
		{
			ft_case_arglenbig(op, arglen);
			// op->zerolen = 0;
			// op->big[1]	 = ft_get_max(arglen, op->width);
			// if (op->big[1] == 0)
			// 	op->blank = 0;
			// else
			// {				
			// 	op->blank = op->width - arglen - op->miner;
			// 	if (op->zero == 1 && op->dot == 0 && op->precision == 0)//precision < 0 일때 * 로 받으면 0precion 무시후 0 플래그 적용
			// 	{
			// 		op->zerolen = op->blank;
			// 		op->blank = 0;
			// 	}				
			// }
		}
		else
		{
			ft_case_precisionbig(op, arglen);
			// op->zerolen = op->precision - arglen;
			// op->big[1]	 = ft_get_max(op->precision, op->width);
			// if (op->big[1] == 0)
			// {
			// 	op->blank = 0;
			// }
			// else
			// {
			// 	op->blank = op->width - op->precision - op->miner;				
			// }			
		}		
	}
	if (op->blank < 0)
		op->blank = 0;	
	if (op->zerolen < 0)
		op->zerolen = 0;
	op->total += (op->blank + op->zerolen);
}


int			ft_get_nbrlen(ssize_t nb, t_op *op)
{
	int		len;

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