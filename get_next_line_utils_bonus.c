/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 00:22:07 by iguidado          #+#    #+#             */
/*   Updated: 2020/02/07 00:25:12 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
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
