/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_process_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:05:28 by yadouble          #+#    #+#             */
/*   Updated: 2018/07/22 17:05:30 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_process_flags(t_var *var)
{
	int		i;
	char	*str;

	i = ft_flags_type_option(var);
	if (var->check.flags & 8 || var->check.type == 'p' ||
		var->check.type == 'P')
	{
		if (var->check.type == 'o' || var->check.type == 'O')
		{
			str = ft_uitoa_base(var->check.nb, BASE_8);
			str[var->check.len] = '\0';
			if (str[0] != '0' && ((var->check.precwidth <= var->check.len &&
				var->check.nb) || (var->check.prec & 1 && !var->check.precwidth
				&& !var->check.nb)))
				ft_buffer(var, '0');
		}
	}
	ft_process_flags_2(var, i);
}

void	ft_process_flags_2(t_var *var, int i)
{
	if (var->check.flags & 8 || var->check.type == 'p' ||
		var->check.type == 'P')
	{
		if ((var->check.type == 'x' && var->check.nb) ||
			(var->check.type == 'p'))
		{
			ft_buffer(var, '0');
			ft_buffer(var, 'x');
		}
		else if ((var->check.type == 'X' && var->check.nb) ||
				(var->check.type == 'P'))
		{
			ft_buffer(var, '0');
			ft_buffer(var, 'X');
		}
	}
	if (var->check.flags & 16 && (!(var->check.flags & 1)) &&
			!var->check.prec && var->check.type != 'c' && i != -1)
		while (i++ < var->check.width - var->check.len)
			ft_buffer(var, '0');
}

void	ft_process_minus(t_var *var, int neg)
{
	int i;

	i = ft_minus_type_option(var, neg);
	if (var->check.flags & 1 && i >= 0)
	{
		if (var->check.precwidth > 0 && var->check.prec & 1 &&
			var->check.type != 'c')
		{
			if (var->check.type == 's' || var->check.type == 'S' ||
				(var->check.type == 's' && var->check.conv & 4))
			{
				while (i++ < var->check.width - var->check.len)
					ft_buffer(var, ' ');
				i -= 1;
			}
			while (i++ < var->check.width - (var->check.len +
					(var->check.precwidth - var->check.len)))
				ft_buffer(var, ' ');
		}
		else
			while (i++ < var->check.width - var->check.len)
				ft_buffer(var, ' ');
	}
}
