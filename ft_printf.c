/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 06:09:24 by doyun             #+#    #+#             */
/*   Updated: 2021/03/16 06:54:36 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list ap;
	t_op	op;
	t_arg	arg;
	int		chk;
	char	*temp_format;
	
	if (!format)
		return (0);		
	chk = 0;
	va_start(ap, format);
	temp_format = (char *)format;
    chk = ft_checkvalid(ap, &temp_format, &op, &arg);
	if (chk == -1)
		return (-1);
	return (op.total);
}
