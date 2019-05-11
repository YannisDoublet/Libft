/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_hexadecimal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 15:13:23 by yadouble          #+#    #+#             */
/*   Updated: 2018/07/16 15:18:16 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_conv_type_hex(t_var *var)
{
	var->check.nb = 0;
	if (var->check.conv & 16)
		var->check.nb = va_arg(var->check.arg, uintmax_t);
	else if (var->check.conv & 8)
		var->check.nb = va_arg(var->check.arg, unsigned long long);
	else if (var->check.conv & 32)
		var->check.nb = va_arg(var->check.arg, size_t);
	else if (var->check.conv & 4)
		var->check.nb = va_arg(var->check.arg, unsigned long);
	else if (!var->check.conv)
		var->check.nb = va_arg(var->check.arg, unsigned int);
	else if (var->check.conv & 1)
		var->check.nb = (unsigned short)va_arg(var->check.arg, unsigned int);
	else if (var->check.conv & 2)
		var->check.nb = (unsigned char)va_arg(var->check.arg, unsigned int);
}

void	ft_process_hexadecimal(t_var *var)
{
	int		i;
	char	*str;

	i = 0;
	if (var->check.nb == 0 && (var->check.prec && (!(var->check.precwidth))))
		return ;
	if (var->check.nb == 0)
	{
		ft_buffer(var, '0');
		ft_process_minus(var, 0);
		return ;
	}
	if (var->check.type == 'x' || var->check.type == 'p')
		str = ft_uitoa_base(var->check.nb, MIN_BASE_16);
	if (var->check.type == 'X' || var->check.type == 'P')
		str = ft_uitoa_base(var->check.nb, MAJ_BASE_16);
	str[var->check.len] = '\0';
	while (i < var->check.len)
	{
		ft_buffer(var, str[i]);
		i++;
	}
	ft_process_minus(var, 0);
}
