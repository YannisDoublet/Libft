/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_large_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 15:04:40 by yadouble          #+#    #+#             */
/*   Updated: 2018/07/18 16:13:44 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_one_byte_char(t_var *var)
{
	ft_buffer(var, var->check.c);
	var->check.a = 1;
}

void	ft_print_two_bytes_char(t_var *var)
{
	if (var->check.type == 'c' && !var->check.conv)
		ft_print_one_byte_char(var);
	else
	{
		ft_buffer(var, ((var->check.c >> 6) + 0xC0));
		ft_buffer(var, ((var->check.c & 0x3F) + 0x80));
	}
	var->check.a = 1;
}

void	ft_print_three_bytes_char(t_var *var)
{
	if (var->check.type == 'c' && !var->check.conv)
		ft_print_one_byte_char(var);
	else
	{
		ft_buffer(var, ((var->check.c >> 12) + 0xE0));
		ft_buffer(var, (((var->check.c >> 6) & 0x3F) + 0x80));
		ft_buffer(var, ((var->check.c & 0x3F) + 0x80));
	}
	var->check.a = 1;
}

void	ft_print_four_bytes_char(t_var *var)
{
	if (var->check.type == 'c' && !var->check.conv)
		ft_print_one_byte_char(var);
	else
	{
		ft_buffer(var, (var->check.c >> 18) + 0xF0);
		ft_buffer(var, (((var->check.c >> 12) & 0x3F) + 0x80));
		ft_buffer(var, (((var->check.c >> 6) & 0x3F) + 0x80));
		ft_buffer(var, ((var->check.c & 0x3F) + 0x80));
	}
	var->check.a = 1;
}

void	ft_process_large_char(t_var *var)
{
	var->check.a = -1;
	if ((var->check.type == 'c' || var->check.type == 'C') &&
		ft_surrogates(var) == -1)
		return ;
	if (var->check.c < 0 && var->check.type == 'c')
		ft_print_one_byte_char(var);
	else if (var->check.c >= 0 && var->check.c <= 127)
		ft_print_one_byte_char(var);
	else if (var->check.c > 127 && var->check.c <= 2047 && MB_CUR_MAX > 1)
		ft_print_two_bytes_char(var);
	else if (var->check.c > 2047 && var->check.c <= 65536 && MB_CUR_MAX > 1)
		ft_print_three_bytes_char(var);
	else if (var->check.c > 65536 && var->check.c <= 1141111 && MB_CUR_MAX > 1)
		ft_print_four_bytes_char(var);
	if (var->check.type == 'c' || var->check.type == 'C')
		ft_process_minus(var, 0);
}
