/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:15:42 by yadouble          #+#    #+#             */
/*   Updated: 2018/08/14 17:00:24 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_itoa_base(intmax_t conv, char *base_to)
{
	long int	i;
	long int	base_len;
	char		str[BUFF_SIZE];
	long int	cmp;
	uintmax_t	numcpy;

	base_len = ft_strlen(base_to);
	ft_bzero(str, BUFF_SIZE);
	i = -1;
	cmp = 0;
	numcpy = conv;
	while (numcpy != 0)
	{
		numcpy = numcpy / base_len;
		cmp++;
	}
	while (++i < cmp)
	{
		str[i] = base_to[(conv % base_len)];
		conv = conv / base_len;
	}
	return (ft_strrev(str));
}
