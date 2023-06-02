/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 00:21:56 by iguidado          #+#    #+#             */
/*   Updated: 2020/02/07 00:24:52 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>
#include <stdlib.h>

int	ft_manage_buf(char *buf)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (buf[i] && buf[i] != '\n')
	{
		buf[i] = '\0';
		i++;
	}
	if (buf[i] == '\0')
		return (0);
	while (++i < BUFFER_SIZE)
	{
		buf[j] = buf[i];
		j++;
	}
	while (j < BUFFER_SIZE)
	{
		buf[j] = 0;
		j++;
	}
	return (1);
}

int	ft_dump_line(char *buf, char **line)
{
	int		i;
	int		j;
	char	*new;

	if (!*buf)
		return (0);
	i = 0;
	j = 0;
	while (buf[i] && buf[i] != '\n' && i < BUFFER_SIZE)
		i++;
	while ((*line) && (*line)[j])
		j++;
	new = (char *)malloc(sizeof(char) * (i + j + 1));
	new[i + j] = 0;
	while (i-- > 0)
		new[j + i] = buf[i];
	while (j-- > 0)
		new[j] = (*line)[j];
	if (*line)
		free(*line);
	*line = new;
	return (ft_manage_buf(buf));
}

int	get_next_line(int fd, char **line)
{
	static t_buflist	*lst = NULL;
	t_buflist			*buflst;
	int					ret;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	*line = NULL;
	buflst = ft_get_fd(&lst, fd);
	while (!ft_dump_line(buflst->buffer, line))
	{
		if ((ret = read(fd, buflst->buffer, BUFFER_SIZE)) < 1)
		{
			if (!*line)
			{
				*line = (char *)malloc(sizeof(char));
				**line = 0;
			}
			if (ret == -1)
				ft_del_fd(fd, &lst);
			return (ret);
		}
	}
	return (1);
}
