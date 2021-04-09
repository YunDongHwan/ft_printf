#include "ft_printf.h"

void        ft_case_cpper(t_op *op, int arglen)
{
    op->blank = op->width - arglen;
		if (op->zero == 1 && op->sign == 0)
		{
			op->zerolen = op->blank;
			op->blank = 0;
		}
}

void        ft_case_str(t_op *op, int arglen)
{
    op->blank = op->width - arglen;
	if (op->precision < arglen && op->precision > 0)
		op->blank += (arglen - op->precision);
}

void        ft_case_arglenbig(t_op *op, int arglen)
{
    op->zerolen = 0;
    op->big[1]	 = ft_get_max(arglen, op->width);
    if (op->big[1] == 0)
        op->blank = 0;
    else
    {				
        op->blank = op->width - arglen - op->miner;
        if (op->zero == 1 && op->dot == 0 && op->precision == 0)//precision < 0 일때 * 로 받으면 0precion 무시후 0 플래그 적용
        {
            op->zerolen = op->blank;
            op->blank = 0;
        }				
    }
}

void        ft_case_precisionbig(t_op *op, int arglen)
{
    op->zerolen = op->precision - arglen;
    op->big[1]	 = ft_get_max(op->precision, op->width);
    if (op->big[1] == 0)
        op->blank = 0;
    else
        op->blank = op->width - op->precision - op->miner;
}