/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 19:53:16 by yadouble          #+#    #+#             */
/*   Updated: 2018/08/14 17:05:23 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	while (s1[i])
		i++;
	while (x < n && s2[x])
		s1[i++] = s2[x++];
	s1[i] = '\0';
	return (s1);
}
