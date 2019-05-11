/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 14:12:04 by yadouble          #+#    #+#             */
/*   Updated: 2018/08/14 16:56:25 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (nb % i != 0)
		i++;
	if (i == nb)
		return (1);
	else
		return (0);
}

int		ft_find_next_prime(int nb)
{
	int	i;

	i = nb;
	while (ft_is_prime(i) != 1)
		i++;
	return (i);
}
