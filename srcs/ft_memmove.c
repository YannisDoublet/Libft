/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 18:13:59 by yadouble          #+#    #+#             */
/*   Updated: 2018/08/14 17:02:57 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*srcs;

	dst = (unsigned char *)dest;
	srcs = (unsigned char *)src;
	if (dst > srcs)
	{
		i = n;
		while (i > 0)
		{
			dst[i - 1] = srcs[i - 1];
			i--;
		}
	}
	else
		ft_memcpy(dst, srcs, n);
	return (dst);
}
