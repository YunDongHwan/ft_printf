/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkvalid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 04:59:01 by doyun             #+#    #+#             */
/*   Updated: 2021/03/17 02:29:30 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_checkargtype(char **format, t_arg *arg)
{
	if (**format == 'c')
		arg->c = 1;
	else if ( **format == 's')
		arg->s = 1;
	else if (**format == 'p')	
		arg->p = 1;
	else if (**format == 'd')	
		arg->d = 1;
	else if (**format == 'i')
		arg->i = 1;
	else if (**format == 'u')
		arg->u = 1;
	else if (**format == 'x')
		arg->x = 1;
	else if (**format == 'X')
		arg->X = 1;
	else if (**format == '%')
		arg->per = 1;
	else
		return (-1);
	return (0);
}

void			ft_checkflag(char **format, t_op *op)
{
	(*format)++;
	while (**format == '-' || **format == '0')
	{
		if (**format == '-')
			op->sign = 1;
		else if (**format == '0')
			op->zero = 1;
		(*format)++;		
	}
}

int				ft_checkprecision(va_list ap, char **format, t_op *op)
{
	if (**format == '.') //식별자가 뒤에 없으면 에러처리
	{
		(*format)++;
		if ((**format) == '*' || (**format >= '0' && **format <= '9'))
			ft_putprecision(op, format, ap);
		else
			op->dot = 1;
	}
	else
		op->nodot = 1;
	if (op->width >= 2147483647)
		return (-1);
	return (0);
}


int			ft_checkwidth(va_list ap, char **format, t_op *op)
{
	while (((**format >= '0') && (**format <= '9')))
	{
		op->width = (op->width * 10) + (**format) - 48;
		(*format)++;
	}
	if (*(*format) == '*')
	{
		op->width = va_arg(ap, int);		   		
		if (op->width < 0)
		{
			if (op->sign == 0)
			{
				op->sign = 1;
				op->zero = 0;
			}
			op->width *= -1;
		}
		(*format)++;
	}
	if (op->width >= 2147483647)	
		return (-1);
	return (0);
}

int				ft_checkvalid(va_list ap, char **format, t_op *op, t_arg *arg)
{	
	op->total = 0;
	while (**format)
	{
		if (**format == '%')
		{
			ft_reset_op(op, arg);
			ft_checkflag(format, op);				
			op->chk = ft_checkwidth(ap, format, op);				
			op->chk = ft_checkprecision(ap, format, op);		
			op->chk = ft_checkargtype(format, arg);
			op->chk = ft_apply_option(ap, op, arg);
			if (op->chk == -1)
				return (-1);	
			(*format)++;
		}
		else
		{
			ft_putchar_fd(**format, 1);
			(op->total)++;
			(*format)++;
		}
	}
	return (0);
}