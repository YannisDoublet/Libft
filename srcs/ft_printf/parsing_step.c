/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_step.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 21:35:55 by yadouble          #+#    #+#             */
/*   Updated: 2018/06/19 16:08:54 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_parse_flags(const char *fmt, t_var *var)
{
	while ((fmt[var->check.i] == '-') || (fmt[var->check.i] == '+') ||
		(fmt[var->check.i] == ' ') || (fmt[var->check.i] == '#') ||
		(fmt[var->check.i] == '0'))
	{
		if (fmt[var->check.i] == '-')
			var->check.flags |= 1;
		else if (fmt[var->check.i] == '+')
			var->check.flags |= 1 << 1;
		else if (fmt[var->check.i] == ' ')
			var->check.flags |= 1 << 2;
		else if (fmt[var->check.i] == '#')
			var->check.flags |= 1 << 3;
		else if (fmt[var->check.i] == '0')
			var->check.flags |= 1 << 4;
		var->check.i++;
	}
}

void	ft_parse_width(const char *fmt, t_var *var)
{
	if (fmt[var->check.i] >= '0' && fmt[var->check.i] <= '9')
	{
		var->check.width = ft_atoi(fmt + var->check.i);
		while (fmt[var->check.i] >= '0' && fmt[var->check.i] <= '9')
			var->check.i++;
	}
}

void	ft_parse_precision(const char *fmt, t_var *var)
{
	if (fmt[var->check.i] == '.')
	{
		var->check.prec |= 1;
		var->check.i++;
		if (fmt[var->check.i] >= '0' && fmt[var->check.i] <= '9')
			var->check.precwidth = ft_atoi(fmt + var->check.i);
		while (fmt[var->check.i] >= '0' && fmt[var->check.i] <= '9')
			var->check.i++;
	}
}

void	ft_parse_conv(const char *fmt, t_var *var)
{
	if (fmt[var->check.i] == 'h' && fmt[var->check.i + 1] == 'h')
		var->check.conv |= 1 << 1;
	else if (fmt[var->check.i] == 'l' && fmt[var->check.i + 1] == 'l')
		var->check.conv |= 1 << 3;
	else if (fmt[var->check.i] == 'h')
		var->check.conv |= 1;
	else if (fmt[var->check.i] == 'l')
		var->check.conv |= 1 << 2;
	else if (fmt[var->check.i] == 'j')
		var->check.conv |= 1 << 4;
	else if (fmt[var->check.i] == 'z')
		var->check.conv |= 1 << 5;
	if (var->check.conv != 0)
	{
		if (var->check.conv & 2 || var->check.conv & 8)
			var->check.i += 2;
		else if (var->check.conv & 1 || var->check.conv & 4 ||
					var->check.conv & 16 || var->check.conv & 32)
			var->check.i++;
	}
}

void	ft_parse_type(const char *fmt, t_var *var)
{
	if (fmt[var->check.i])
	{
		var->check.c = 0;
		if (((fmt[var->check.i] == 's') || (fmt[var->check.i] == 'S') ||
			(fmt[var->check.i] == 'p') || (fmt[var->check.i] == 'd') ||
			(fmt[var->check.i] == 'D') || (fmt[var->check.i] == 'i') ||
			(fmt[var->check.i] == 'o') || (fmt[var->check.i] == 'O') ||
			(fmt[var->check.i] == 'u') || (fmt[var->check.i] == 'U') ||
			(fmt[var->check.i] == 'x') || (fmt[var->check.i] == 'X') ||
			(fmt[var->check.i] == 'c') || (fmt[var->check.i] == 'C' ||
			fmt[var->check.i] == 'P')))
			var->check.type = fmt[var->check.i];
		else
		{
			var->check.c = fmt[var->check.i];
			var->check.type = 'c';
		}
		var->check.i++;
	}
}
