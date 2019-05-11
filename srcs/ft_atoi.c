/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 18:54:18 by yadouble          #+#    #+#             */
/*   Updated: 2018/08/14 16:56:07 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_atoi(const char *nptr)
{
	size_t	i;
	int		res;
	int		neg;

	i = 0;
	res = 0;
	neg = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == ' '))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		neg = ((nptr[i] == '-') ? -1 : 1);
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (nptr[i] - '0') + res * 10;
		i++;
	}
	return (res * neg);
}
