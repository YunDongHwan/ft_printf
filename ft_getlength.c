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
	if (arg->c ||  arg->p)
		op->blank = op->width - arglen;
	else if(arg->s)
	{
		op->blank = op->width - arglen;
		if (op->precision < arglen && op->precision > 0)
			op->blank += (arglen - op->precision);
	}	
	else if (arg->d || arg->u)
	{
		op->blank = op->width - ft_get_max(op->precision, arglen);	
		// printf("op->precision : %d\n", op->precision);
		// printf("arglen : %d\n", arglen);						
		op->zerolen = op->precision - arglen;	
		printf("op->zerolen : %d\n", op->zerolen);
		if (op->zero == 1 && op->nodot == 1)
		{
			op->zerolen = op->width - arglen - op->miner;
			op->blank = 0;									
		}
		else if (op->zero == 1 && op->nodot == 0)
			op->zerolen = op->width - arglen - op->blank;						
		if (op->miner == 1)
		{
			op->total += 1;
			op->blank -= 1;
		}
	}
	if (op->blank < 0)
		op->blank = 0;	
	op->total += (op->blank + op->zerolen);		
	  printf("op->blank : %d\n", op->blank);
	 printf("op->width : %d\n", op->width);
	  printf("op->precision : %d\n", op->precision);
	  printf("op->zerolen : %d\n", op->zerolen);
	  printf("op->zero : %d\n", op->zero);
	  printf("arglen : %d\n", arglen);
}


int			ft_get_nbrlen(int nb, t_op *op)
{
	int		len;

	len = 0;
	if (nb < 0)
	{
		op->miner = 1;
		nb *= -1;
	}
	while (nb)
	{
		nb /= 10;
		len++;
	}
	op->total += len;
	return (len);
}