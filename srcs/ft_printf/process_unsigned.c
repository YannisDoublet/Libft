/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 19:52:53 by yadouble          #+#    #+#             */
/*   Updated: 2018/07/18 16:14:35 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_conv_type_uns(t_var *var)
{
	var->check.unb = 0;
	if (var->check.type == 'U')
		var->check.unb = va_arg(var->check.arg, long unsigned);
	else if (var->check.conv & 1)
		var->check.unb = (unsigned short)va_arg(var->check.arg, unsigned int);
	else if (var->check.conv & 2)
		var->check.unb = (unsigned char)va_arg(var->check.arg, unsigned int);
	else if (var->check.conv & 4)
		var->check.unb = va_arg(var->check.arg, unsigned long int);
	else if (var->check.conv & 8)
		var->check.unb = va_arg(var->check.arg, unsigned long long int);
	else if (var->check.conv & 16)
		var->check.unb = va_arg(var->check.arg, uintmax_t);
	else if (var->check.conv & 32)
		var->check.unb = va_arg(var->check.arg, size_t);
	else if (var->check.conv == 0)
		var->check.unb = va_arg(var->check.arg, unsigned int);
}

void	ft_process_unsigned(t_var *var)
{
	char		str[BUFF_SIZE];
	int			i;
	int			len;

	i = 0;
	len = var->check.len;
	if (var->check.unb == 0 && (var->check.prec && (!(var->check.precwidth))))
		return ;
	ft_bzero(str, BUFF_SIZE);
	while (len--)
	{
		str[i++] = var->check.unb % 10 + '0';
		var->check.unb /= 10;
	}
	while (i > 0)
		ft_buffer(var, str[--i]);
	ft_process_minus(var, 0);
}
