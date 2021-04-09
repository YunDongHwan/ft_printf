#include "ft_printf.h"

void        ft_putprecision(t_op *op, char **format, va_list ap)
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

void        ft_putargd(t_op *op, int nb)
{
    if (op->sign == 0)
        ft_putblank(op);
    ft_putnbr(nb, op);
    if (op->sign == 1)
        ft_putblank(op);
}

void        ft_putargu(t_op *op, unsigned int nb)
{
    if (op->sign == 0)
        ft_putblank(op);
    ft_putnbr(nb, op);
    if (op->sign == 1)
        ft_putblank(op);
}

void        ft_putargx(t_op *op, char *hex)
{
    if (op->sign == 0)
        ft_putblank(op);
    ft_puthex(op, hex);
    if (op->sign == 1)
        ft_putblank(op);
}