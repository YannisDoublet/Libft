/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 21:14:53 by yadouble          #+#    #+#             */
/*   Updated: 2018/07/16 13:47:52 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_buffer(t_var *var, char c)
{
	if (ft_strlen(var->check.buff) > BUFF_SIZE)
	{
		write(1, var->check.buff, BUFF_SIZE);
		var->check.total += var->check.bix;
		ft_bzero(var->check.buff, var->check.bix);
		var->check.bix = 0;
	}
	var->check.buff[var->check.bix] = c;
	var->check.bix++;
}
