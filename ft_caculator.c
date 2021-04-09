/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calulator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 23:00:59 by doyun             #+#    #+#             */
/*   Updated: 2021/03/16 23:01:19 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_get_max(int num1, int num2)
{
	if (num1 >= num2)
		return (0);
	else
		return (1);
}

int			ft_get_hexlen(size_t p)
{
	int		count;

	count = 0;
	while (p > 0)
	{
		p /= 16;
		count++;
	}
	return (count);
}

char		*ft_change_hex(size_t p, t_arg *arg, t_op *op)
{
	char	*hex;
	int		len;
	char	*x;
	char	*bigx;

	x = "0123456789abcdef";
	bigx = "0123456789ABCDEF";
	len = ft_get_hexlen(p);
	hex = (char *)ft_calloc(sizeof(char), len + 1);
	if (!hex)
		return (NULL);
	if (p == 0 && op->dot == 0)
	{
		hex = ft_strdup("0");
		return (hex);
	}
	while (--len >= 0)
	{
		if (arg->x == 1 || arg->p == 1)
			hex[len] = x[p % 16];
		else if (arg->bigx == 1)
			hex[len] = bigx[p % 16];
		p /= 16;
	}
	return (hex);
}

void		ft_putnbr(ssize_t nb, t_op *op)
{
	if (nb < 0)
		write(1, "-", 1);
	if (nb == -2147483648)
	{
		ft_putzero(op);
		write(1, "2147483648", 10);
	}
	if (nb < 0)
		nb *= -1;
	ft_putzero(op);
	if (nb >= 0 && nb <= 9)
		ft_putchar_fd(nb + '0', 1);
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, op);
		ft_putchar_fd(nb % 10 + '0', 1);
	}
}

void		ft_puthex(t_op *op, char *hex)
{
	int		len;

	len = ft_strlen(hex);
	ft_putzero(op);
	ft_putstr_fd(hex, 1);
	op->total += len;
}
