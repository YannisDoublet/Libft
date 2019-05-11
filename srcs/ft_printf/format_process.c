/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:05:35 by yadouble          #+#    #+#             */
/*   Updated: 2018/07/22 17:05:38 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_process_width(t_var *var)
{
	int i;

	ft_len(var);
	i = ft_width_type_option(var);
	if (var->check.width > 0 && (!(var->check.flags & 1)) && i != -1)
	{
		if (var->check.prec & 1 && var->check.precwidth >= 0)
		{
			if ((var->check.type == 'c' || var->check.type == 's' ||
				var->check.type == 'S') && var->check.flags & 16)
				return ;
			while ((i < var->check.width - var->check.precwidth &&
					i < var->check.width - var->check.len)
					|| ((i < var->check.width - var->check.len ||
						i < var->check.width - var->check.precwidth) &&
					var->check.type == 's'))
			{
				ft_buffer(var, ' ');
				i++;
			}
			i = -1;
		}
		ft_process_width_2(var, i);
	}
}

void	ft_process_width_2(t_var *var, int i)
{
	if (i != -1 && !var->check.precwidth && ((!(var->check.flags & 16))
		|| (var->check.prec & 1 && (var->check.type != 'c' ||
		var->check.type != 's'))))
		while (i < var->check.width - var->check.len)
		{
			ft_buffer(var, ' ');
			i++;
		}
}

void	ft_process_prec(t_var *var)
{
	int i;

	i = 0;
	if (var->check.prec & 1)
	{
		ft_prec_type_option(var);
		while (i++ < var->check.precwidth - var->check.len)
			ft_buffer(var, '0');
	}
}
