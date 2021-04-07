/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 06:16:19 by doyun             #+#    #+#             */
/*   Updated: 2021/03/17 01:37:21 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include <stdio.h>

typedef struct	s_op
{
	int			sign;
	int			miner;
	int			zero;
	int			zerolen;
	int			width;
	int			precision;
	int			dot;
	int			nodot;
	int			blank;
	int			total;
	int			p_ast;
	int			big[2];
}				t_op;

typedef struct	s_arg
{
	int			c;
	int			s;
	int			p;
	int			d;
	int			i;
	int			u;
	int			x;
	int			X;
	int			per;
}				t_arg;

int				ft_printf(const char *format, ...);

// //ft_apply_op
// void			ft_apply_char(va_list ap, t_op *op, t_arg *arg);
// void			ft_apply_str(va_list ap, t_op *op, t_arg *arg);
int				ft_apply_option(va_list ap, t_op *op, t_arg *arg);

// //ft_checkvalid.c
// int			ft_checkargtype(char **format, t_arg *arg);
// int			ft_checkflag(char **format, t_op *op);
// int			ft_checkprecision(va_list zp, char **format, t_op *op);
// int			check_width(va_list ap, char **format, t_op *op);
// int			ft_checkper(va_list ap, char **format, t_op *op, t_arg *arg);
int				ft_checkvalid(va_list ap, char **format, t_op *op, t_arg *arg);

//ft_caculator.c
int				ft_get_max(int num1, int num2);
char			*ft_change_hex(size_t i, t_arg *arg, t_op *op);
void			ft_putnbr(int nb, t_op *op);

//ft_getlength.c
void			ft_get_blanklen(t_op *op, int arglen, t_arg *arg);
int				ft_get_nbrlen(int nb, t_op *op);

//ft_putarg.c
void			ft_putblank(t_op *op);
void			ft_putzero(t_op *op);
void			ft_reset_op(t_op *op, t_arg *arg);


#endif
