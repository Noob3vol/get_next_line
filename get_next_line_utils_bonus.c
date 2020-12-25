/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:53:21 by iguidado          #+#    #+#             */
/*   Updated: 2020/12/23 09:08:37 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h> //printf

t_lkd_buff	*ft_create_lkd_buff(int fd, t_lkd_buff *next)
{
	t_lkd_buff	*new;
	int			i;

	if (!(new = (t_lkd_buff *)malloc(sizeof(t_lkd_buff))))
		return (NULL);
	new->fd = fd;
	new->next = next;
	i = 0;
	while (i < BUFF_SIZE)
	{
		new->buff[i] = 0;
		i++;
	}
	return (new);
}

char *ft_get_node(int fd, t_lkd_buff **node_start)
{
	t_lkd_buff	*next;
	t_lkd_buff	*prev;
	t_lkd_buff	*fd_buff;

	fd_buff = *node_start;
	if (!fd_buff)
	{
		if (!(fd_buff = ft_create_lkd_buff(fd, NULL)))
			return (NULL);
		*node_start = fd_buff;
		printf("\n--- creating head node fd = %d ---\n", fd_buff->fd);
		return (fd_buff->buff);
	}
	prev = NULL;
	while (fd_buff && fd < fd_buff->fd)
	{
		prev = fd_buff;
		fd_buff = fd_buff->next;
	}
	if (!fd_buff || fd > fd_buff->fd)
	{
		next = fd_buff;
		if (!prev)
		{
			if(!(*node_start = ft_create_lkd_buff(fd, next)))
				return (NULL);
			return ((*node_start)->buff);
		}
		fd_buff = prev;
		if (!(fd_buff->next = ft_create_lkd_buff(fd, next)))
			return (NULL);
		fd_buff = fd_buff->next;
	}
	return (fd_buff->buff);
}

void	ft_free_node(int fd, t_lkd_buff **origin_fd_buff)
{
	t_lkd_buff  *current;
	t_lkd_buff	*next;
	t_lkd_buff	*prev;

	prev = NULL;
	current = *origin_fd_buff;
	if (fd == current->fd)
	{
		next = current->next;
		free(current);
		*origin_fd_buff = next;
		return ;
	}
	while (fd < current->fd)
	{
		prev = current;
		current = current->next;
	}
	next = current->next;
	free(current);
}
