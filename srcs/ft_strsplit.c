/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 14:44:44 by yadouble          #+#    #+#             */
/*   Updated: 2018/08/14 17:06:34 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static	int		is_word(const char *str, char c)
{
	int			m;
	size_t		i;

	m = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i])
			m++;
		while (str[i] != c && str[i])
			i++;
	}
	return (m);
}

static	char	**ft_split(char **tab, char c, size_t l, const char *str)
{
	size_t		save;
	size_t		i;
	size_t		n;

	save = 0;
	i = 0;
	n = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		save = i;
		while (str[i] != c && str[i])
		{
			i++;
			l++;
		}
		if (!(tab[n] = malloc(sizeof(char) * (l + 1))))
			return (NULL);
		tab[n] = ft_strsub(str, save, l);
		n++;
		l = 0;
	}
	return (tab);
}

char			**ft_strsplit(const char *str, char c)
{
	int			m;
	size_t		l;
	char		**tab;
	int			n;

	if (str == NULL)
		return (NULL);
	m = is_word(str, c);
	n = 0;
	l = 0;
	if (!(tab = malloc(sizeof(char *) * (m + 1))))
		return (NULL);
	tab = ft_split(tab, c, l, str);
	tab[is_word(str, c)] = 0;
	return (tab);
}
