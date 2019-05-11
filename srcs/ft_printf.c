/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 20:46:12 by yadouble          #+#    #+#             */
/*   Updated: 2018/07/24 16:24:08 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_var	var;

	var.check.total = 0;
	ft_bzero(var.check.buff, BUFF_SIZE);
	va_start(var.check.arg, format);
	ft_parsing_control(&var, format);
	if (var.check.save_bix > 0 && var.check.a == -1)
		write(1, var.check.buff, var.check.save_bix);
	else
		write(1, var.check.buff, var.check.bix);
	if (var.check.a == -1)
		return (-1);
	else if (var.check.save_bix > 0 && var.check.a == -1)
		return (var.check.save_bix);
	else if (var.check.type == 'S' ||
		(var.check.type == 's' && var.check.conv & 4))
		return (var.check.bix + var.check.total);
	return (var.check.bix + var.check.total);
}
