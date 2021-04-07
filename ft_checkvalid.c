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
//			printf("check arg foramt : %c\n", **format);
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
		return (0);
	return (1);
}

int			ft_checkflag(char **format, t_op *op)
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
//	printf("check format in flag %c\n", **format);
	return (1);
}



int				ft_checkprecision(va_list ap, char **format, t_op *op)
{
	if (**format == '.') //식별자가 뒤에 없으면 에러처리
	{
		(*format)++;
		if ((**format) == '*' || (**format >= '0' && **format <= '9'))
		{
			if (**format == '*')
			{
				op->precision = va_arg(ap, int);
				op->p_ast = 1;		
				(*format)++;
			}	
			while (**format >= '0' && **format <= '9')
			{
				op->precision = (op->precision * 10) + **format - 48;
				(*format)++;
			}
			if (op->precision == 0)
			 	op->dot = 1;			
		}
		else
			op->dot = 1;
	}
	else
		op->nodot = 1;
	return (1);
}


int			ft_checkwidth(va_list ap, char **format, t_op *op)
{
	//		printf("check format in width %c\n", **format);
	while (((**format >= '0') && (**format <= '9')))//int형 최대 최소 처리
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
//	printf("widtg format : %c\n", **format);
	//		printf("op->width : %d!\n", op->width);
	return (1);
}

int				ft_checkvalid(va_list ap, char **format, t_op *op, t_arg *arg)
{
	int			chk;

	chk = 0;
	while (**format)
	{
		if (**format == '%')
		{
			ft_reset_op(op, arg);
			chk = ft_checkflag(format, op);	
			if (chk == 0)
				return (0);
			//			printf("flag ok\n");
			//			printf("op->flag, zero : %d, %d\n", op->sign, op->zero);
			chk = ft_checkwidth(ap, format, op);	
			if (chk == 0)
				return (0);
			//						printf("width ok\n");
			chk = ft_checkprecision(ap, format, op);
			if (chk == 0)
				return (0);	
			//						printf("precision ok\n");
			chk = ft_checkargtype(format, arg);
			if (chk == 0)
				return (0);	
			//						printf("argtype ok\n");
			chk = ft_apply_option(ap, op, arg);
			if (chk == 0)
				return (-1);	
			//						printf("apply_option ok\n");
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
