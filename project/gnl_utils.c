/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 16:25:50 by iguidado          #+#    #+#             */
/*   Updated: 2019/12/03 15:10:12 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "outlib.h"
#include <stdlib.h>

t_buflist	*ft_new_fd(t_buflist *old, t_buflist *next, int fd)
{
	int			i;
	t_buflist	*new;

	if (!(new = (t_buflist *)malloc(sizeof(t_buflist))))
		return (NULL);
	new->fd = fd;
	i = -1;
	while (++i < BUFFER_SIZE)
		new->buffer[i] = 0;
	new->next = next;
	if (old)
		old->next = new;
	return (new);
}

t_buflist	*ft_get_fd(t_buflist **buflst, int fd)
{
	t_buflist *start;
	t_buflist *old;
	t_buflist *new;

	old = NULL;
	start = (*buflst);
	while (*buflst && (*buflst)->fd < fd)
	{
		old = (*buflst);
		(*buflst) = (*buflst)->next;
	}
	if (*buflst && fd == (*buflst)->fd)
	{
		new = (*buflst);
		(*buflst) = start;
		return (new);
	}
	if (!(new = ft_new_fd(old, (*buflst), fd)))
		return (NULL);
	(*buflst) = new;
	if (start)
		(*buflst) = start;
	return (new);
}

void		ft_del_fd(int fd, t_buflist **buflst)
{
	t_buflist *start;
	t_buflist *old;

	old = NULL;
	start = (*buflst);
	if (*buflst && fd == (*buflst)->fd)
		start = (*buflst)->next;
	else
	{
		while (*buflst && fd != (*buflst)->fd)
		{
			old = (*buflst);
			(*buflst) = (*buflst)->next;
		}
		old->next = (*buflst)->next;
	}
	if (!*buflst)
		return ;
	free(*buflst);
	(*buflst) = start;
}

static void		ft_clr_buf(char buf[])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (buf[i] && buf[i] != '\n' && i < BUFFER_SIZE)
	{
		buf[i] = '\0';
		i++;
	}
	while (++i < BUFFER_SIZE)
	{
		buf[j] = buf[i];
		j++;
	}
	while (j < BUFFER_SIZE)
	{
		buf[j] = '\0';
		j++;
	}
}

int			ft_dump_buf(char **line, char buffer[])
{
	char	*new;
	int		i;
	int		j;
	int		new_len;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n' && i < BUFFER_SIZE)
		i++;
	new_len = i;
	while ((*line) && (*line)[j])
		j++;
	new_len += j;
	if (!(new = (char *)malloc(sizeof(char) * (new_len + 1))))
		return (-1);
	i = 0;
	j = 0;
	new[new_len] = '\0';
	while ((*line) && (new[j] = (*line)[j]))
		j++;
	while (buffer[i] && buffer[i] != '\n' && i < BUFFER_SIZE)
	{
		new[j + i] = buffer[i];
		i++;
	}
	free(*line);
	*line = new;
	j = (buffer[i] == '\n' ? 0 : 1);
	ft_clr_buf(buffer);
	return (j);
}

