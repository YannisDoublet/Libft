/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 19:02:29 by yadouble          #+#    #+#             */
/*   Updated: 2018/08/14 17:06:48 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strtrim(char const *s)
{
	unsigned int		start;
	int					end;

	if (!s)
		return (NULL);
	start = 0;
	end = ft_strlen(s) - 1;
	while ((s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
			&& s[start])
		start++;
	while ((s[end] == ' ' || s[end] == '\n' || s[end] == '\t') &&
			end > (int)start && s[end])
		end--;
	return (ft_strsub(s, start, (end - start + 1)));
}
