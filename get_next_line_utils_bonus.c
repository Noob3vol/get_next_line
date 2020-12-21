/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:53:21 by iguidado          #+#    #+#             */
/*   Updated: 2020/12/21 15:53:22 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_get_buff(int fd, t_lkd_buff *fd_buff)
{
	t_lkd_buff	*next;
	t_lkd_buff	*prev;

	if (!fd_buff)
	{
		if (!(fd_buff = ft_create_lkd_buff(fd, NULL)))
			return (NULL);
		return (fd_buff->buff);
	}
	while (fd_buff && fd < fd_buff->fd)
	{
		prev = fd_buff;
		fd_buff = fd_buff->next;
	}
	if (!fd_buff || fd > fd_buff->fd)
	{
		next = fd_buff;
		fd_buff = prev;
		if (!(fd_buff->next = ft_create_lkd_buff(fd, next)))
			return (NULL);
		fd_buff = fd_buff->next;
	}
	return (fd_buff->buff);
}
