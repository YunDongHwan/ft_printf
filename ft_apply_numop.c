#include "ft_printf.h"

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
