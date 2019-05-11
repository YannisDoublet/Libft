/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 19:16:11 by yadouble          #+#    #+#             */
/*   Updated: 2018/08/14 17:01:46 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		new->content = (void *)malloc(sizeof(void) * content_size);
		{
			if (ft_memcpy(new->content, content, content_size))
			{
				new->content_size = content_size;
				new->next = NULL;
			}
		}
	}
	else
	{
		new->content = NULL;
		new->content_size = 0;
		new->next = NULL;
	}
	return (new);
}
