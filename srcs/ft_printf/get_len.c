/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 16:54:12 by yadouble          #+#    #+#             */
/*   Updated: 2018/07/22 15:31:23 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_len(t_var *var)
{
	var->check.len = 0;
	if (var->check.type == 'd' || var->check.type == 'D' ||
		var->check.type == 'i')
		ft_numlen(var);
	if (var->check.type == 'x' || var->check.type == 'X' ||
		var->check.type == 'p' || var->check.type == 'P')
		ft_hxlen(var);
	if (var->check.type == 'u' || var->check.type == 'U')
		ft_unsigned_len(var);
	if (var->check.type == 'o' || var->check.type == 'O')
		ft_octlen(var);
	if (var->check.type == 'c' || var->check.type == 'C')
		ft_charlen(var);
	if ((var->check.type == 's' && var->check.conv & 4) ||
		var->check.type == 'S')
		ft_wstringlen(var);
	else if (var->check.type == 's')
		ft_stringlen(var);
}

void	ft_wstringlen(t_var *var)
{
	int i;

	i = 0;
	var->check.strl = va_arg(var->check.arg, wchar_t *);
	if (var->check.strl == NULL)
	{
		var->check.strl = (wchar_t *)L"(null)";
		var->check.len = ft_strlen((char *)var->check.strl);
		return ;
	}
	if (var->check.prec && var->check.precwidth > 0)
		while (var->check.strl[i])
		{
			if (var->check.len + ft_get_wcharlen(var->check.strl[i]) <=
				var->check.precwidth)
				var->check.len += ft_get_wcharlen(var->check.strl[i]);
			else
				break ;
			i++;
		}
	while (var->check.strl[i] && !var->check.prec)
	{
		var->check.len += ft_get_wcharlen(var->check.strl[i]);
		i++;
	}
}

void	ft_stringlen(t_var *var)
{
	if (var->check.type == 's')
	{
		var->check.str = va_arg(var->check.arg, char *);
		if (!var->check.str)
			var->check.str = NULLSTR;
		var->check.len = ft_strlen(var->check.str);
		return ;
	}
}

void	ft_charlen(t_var *var)
{
	if (!var->check.c)
		var->check.c = va_arg(var->check.arg, wchar_t);
	if (var->check.c <= 127)
		var->check.len = 1;
	else if (var->check.c > 127 && var->check.c <= 2047 && MB_CUR_MAX > 1)
		var->check.len = 2;
	else if (var->check.c > 2047 && var->check.c <= 65536 && MB_CUR_MAX > 1)
		var->check.len = 3;
	else if (var->check.c > 65536 && var->check.c <= 1141111 && MB_CUR_MAX > 1)
		var->check.len = 4;
}
