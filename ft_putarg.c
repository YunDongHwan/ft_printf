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

void		ft_putblank(int	i)
{
	while (i--)
		ft_putchar_fd(' ', 1);
}

void		ft_reset_op(t_op *op)
{
	op->sign = 0;
	op->zero = 0;
	op->width = 0;
	op->precision = 0;
	op->blank = 0;
	op->total = 0;
}
