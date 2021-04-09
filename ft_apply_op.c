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

void			ft_apply_char(va_list ap, t_op *op, t_arg *arg)
{
	char		c;

	c = va_arg(ap, int);
	op->precision = 0;
	ft_get_blanklen(op, 1, arg);
	if (op->sign == 0)
		ft_putblank(op);
	ft_putchar_fd(c, 1);
	op->total += 1;
	if(op->sign == 1)
		ft_putblank(op);
}

void			ft_apply_str(va_list ap, t_op *op, t_arg *arg)
{
	char		*str;
	int			len;

	str = "";
	if (op->dot == 0)
	{
		str = va_arg(ap, char *);
		if (str == 0)
			str = "(null)";
	}
	len = ft_strlen(str);
	ft_get_blanklen(op, len, arg);
	if (op->sign == 0)
		ft_putblank(op);
	if (op->precision > 0 && op->precision < len)
	{		
		while (op->precision > 0)
		{
			ft_putchar_fd(*str, 1);
			str++;
			op->total++;
			op->precision--;			
		}
	}
	else
	{
		ft_putstr_fd(str, 1);
		op->total += len;
	}
	if(op->sign == 1)
		ft_putblank(op);
}

void			ft_apply_pnt(va_list ap, t_op *op, t_arg *arg)
{
	size_t 		p;
	char		*temp;
	char		*addr;
	int			len;

	p = va_arg(ap, size_t);	
	temp = ft_change_hex(p, arg, op);
	if (arg->p == 1)
		addr = ft_strjoin("0x", temp);
	else
		addr = ft_strjoin("0X", temp);	
	free(temp);
	op->precision = 0;
	len = ft_strlen(addr);
	op->total += len;
	ft_get_blanklen(op, len, arg);
	if (op->sign == 0)
		ft_putblank(op);
	ft_putstr_fd(addr, 1);
	free(addr);
	if(op->sign == 1)
		ft_putblank(op);		
}

void			ft_apply_d(va_list ap, t_op *op, t_arg *arg)
{
	size_t		nb;
	int			len;
	
	if (arg->d == 1 || arg-> i)
	{		
		nb = va_arg(ap, int);
		if ((op->nodot == 0 && op->precision == 0 && nb == 0) || 
						(op->dot == 1 && nb == 0))
		{
			op->blank = op->width;
			op->total += op->blank;
			ft_putblank(op);		
		}
		else
		{
			len = ft_get_nbrlen(nb, op);
			ft_get_blanklen(op, len, arg);
			ft_putargd(op, nb);
		}
	}
}

void			ft_apply_i(va_list ap, t_op *op, t_arg *arg)
{
	size_t		nb;
	int			len;
	
	if (arg->i == 1)
	{		
		nb = va_arg(ap, int);
		if ((op->nodot == 0 && op->precision == 0 && nb == 0) || 
						(op->dot == 1 && nb == 0))
		{
			op->blank = op->width;
			op->total += op->blank;
			ft_putblank(op);		
		}
		else
		{
			len = ft_get_nbrlen(nb, op);
			ft_get_blanklen(op, len, arg);
			ft_putargd(op, nb);
		}
	}
}

void				ft_apply_u(va_list ap, t_op *op, t_arg *arg)
{
	unsigned int	nb;
	int				len;
	
	if (arg->u == 1)
	{		
		nb = va_arg(ap, unsigned int);		
		if ((op->nodot == 0 && op->precision == 0 && nb == 0) || 
						(op->dot == 1 && nb == 0))
		{
			op->blank = op->width;
			op->total += op->blank;
			ft_putblank(op);		
		}
		else
		{
			len = ft_get_nbrlen(nb, op);
			ft_get_blanklen(op, len, arg);
			ft_putargu(op, nb);
		}
	}
}

void				ft_apply_x(va_list ap, t_op *op, t_arg *arg)
{
	size_t			nb;
	int				len;
	char			*hex;
		
	if (arg->x == 1 || arg->X == 1)
	{		
		nb = va_arg(ap, size_t);
		hex = ft_change_hex(nb, arg, op);		
		len = ft_strlen(hex);
		ft_get_blanklen(op, len, arg);
		ft_putargx(op, hex);		
	}
}

void			ft_apply_per(t_op *op, t_arg *arg)
{	
	ft_get_blanklen(op, 1, arg);	
	if (op->sign == 0)
		ft_putblank(op);
	if (op->zero == 1 && op->sign == 0)
		ft_putzero(op);
	ft_putchar_fd('%', 1);
	op->total += 1;
	if(op->sign == 1)
		ft_putblank(op);		
}

int				ft_apply_option(va_list ap, t_op *op, t_arg *arg)
{	
	if (arg->c == 1)
		ft_apply_char(ap, op, arg);
	else if (arg->s == 1)
		ft_apply_str(ap, op, arg);
	else if (arg->p == 1)
		ft_apply_pnt(ap, op, arg);
	else if (arg->d == 1)
		ft_apply_d(ap, op, arg);
	else if (arg->i == 1)
		ft_apply_i(ap, op, arg);
	else if (arg->u == 1)
		ft_apply_u(ap, op, arg);
	else if (arg->x == 1 || arg->X == 1)
		ft_apply_x(ap, op, arg);	
	else if (arg->per == 1)
		ft_apply_per(op, arg);
	else
		return (-1);
	return (0);
}