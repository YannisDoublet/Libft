/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_option_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:05:00 by yadouble          #+#    #+#             */
/*   Updated: 2018/07/22 17:10:19 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_width_type_option(t_var *var)
{
	int i;

	i = 0;
	if (var->check.type == 'd' || var->check.type == 'i' ||
		var->check.type == 'D')
		if (var->check.nb < 0 || var->check.flags & 2 || var->check.flags & 4)
			i++;
	if ((var->check.type == 'o' || var->check.type == 'O')
		&& (var->check.flags & 8 && var->check.nb != 0))
	{
		i++;
		if (var->check.prec & 1 && var->check.precwidth == 0 &&
			var->check.nb != 0)
		{
			while (i++ < var->check.width - var->check.len)
				ft_buffer(var, ' ');
			i = -1;
		}
	}
	return (ft_width_type_option_2(var, i));
}

int		ft_width_type_option_2(t_var *var, int i)
{
	if (var->check.type == 'p' || var->check.type == 'P')
		i = i + 2;
	if ((var->check.type == 'x' || var->check.type == 'X')
		&& (var->check.flags & 8))
	{
		i = i + 2;
		if (var->check.prec & 1 && var->check.precwidth == 0 &&
			var->check.nb != 0)
		{
			while (i++ < var->check.width - var->check.len)
				ft_buffer(var, ' ');
			i = -1;
		}
		else if (var->check.prec & 1 && var->check.precwidth == 0 &&
			var->check.nb == 0)
			i = i - 2;
	}
	return (ft_width_type_option_3(var, i));
}

int		ft_width_type_option_3(t_var *var, int i)
{
	if (var->check.type == 's' && var->check.prec && !var->check.precwidth &&
		var->check.str != NULLSTR)
	{
		while (i < var->check.width)
		{
			ft_buffer(var, ' ');
			i++;
		}
		i = -1;
		return (i);
	}
	if (var->check.type == 's' && var->check.str && var->check.len == 0 &&
		(!(var->check.flags & 1)))
	{
		while (i < var->check.width - var->check.len)
		{
			ft_buffer(var, ' ');
			i++;
		}
		i = -1;
		return (i);
	}
	return (ft_width_type_option_4(var, i));
}

int		ft_width_type_option_4(t_var *var, int i)
{
	if ((var->check.type == 'S' || (var->check.type == 's' &&
		var->check.conv & 4)) && var->check.prec && var->check.precwidth > 0 &&
		(!(var->check.flags & 1)))
	{
		while (i < var->check.width - var->check.len)
		{
			ft_buffer(var, ' ');
			i++;
		}
		i = -1;
		return (i);
	}
	if ((var->check.nb == 0 && var->check.unb == 0) &&
		var->check.prec && var->check.precwidth == 0)
	{
		while (i++ < var->check.width)
			ft_buffer(var, ' ');
		i = -1;
		return (i);
	}
	return (i);
}
