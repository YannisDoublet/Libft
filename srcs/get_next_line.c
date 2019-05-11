/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 16:14:31 by yadouble          #+#    #+#             */
/*   Updated: 2018/08/14 17:07:08 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_cutstr(t_list **current, int i)
{
	char	*tmp;

	tmp = ft_strdup((char *)(*current)->content);
	free((*current)->content);
	(*current)->content = ft_strsub(tmp, i + 1, ft_strlen(tmp) - i);
	ft_strdel(&tmp);
}

int		ft_current_to_line(t_list *current, char **line)
{
	int	i;

	i = 0;
	while (((char *)current->content)[i] != '\n' &&
		((char *)current->content)[i] != '\0')
		i++;
	*line = ft_strsub((char *)current->content, 0, i);
	return (i);
}

t_list	*ft_wich_fd(t_list **head, int fd)
{
	t_list	*current;

	current = *head;
	while (current)
	{
		if (fd == (int)current->content_size)
			return (current);
		current = current->next;
	}
	current = ft_lstnew("\0", fd);
	ft_lstadd(head, current);
	return (current);
}

int		get_next_line(const int fd, char **line)
{
	int				ret;
	char			buff[BUFF_SIZE + 1];
	static	t_list	*head;
	t_list			*current;
	char			*tmp;

	if (line == NULL || BUFF_SIZE < 1 || read(fd, buff, 0) < 0 || fd < 0)
		return (-1);
	current = ft_wich_fd(&head, fd);
	if (ft_strchr((char *)current->content, '\n') == NULL)
		while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
		{
			buff[ret] = '\0';
			tmp = ft_strjoin((char *)current->content, buff);
			ft_memdel(&current->content);
			current->content = ft_strdup(tmp);
			ft_strdel(&tmp);
			if (ft_strchr((char *)current->content, '\n'))
				break ;
		}
	ret = ft_current_to_line(current, line);
	if (ret <= 0 && !ft_strchr((char *)current->content, '\n'))
		return (0);
	ft_cutstr(&current, ret);
	return (1);
}
