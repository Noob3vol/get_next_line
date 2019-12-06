/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 03:30:31 by iguidado          #+#    #+#             */
/*   Updated: 2019/12/06 01:03:48 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

int	ft_handle_error(int fd, char **line)
{
	if (fd < 0)
		return (1);
	if (!line)
		return (1);
	*line = NULL;
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char buffer[BUFFER_SIZE] = "";
	int			ret;

	if(ft_handle_error(fd, line))
		return (-1);
	while (ft_dump_buf(buffer, line) == 1)
	{
		if ((ret = read(fd, buffer, BUFFER_SIZE)) <= 0)
		{
			if (!ret)
			{
				if (*line)
					free(*line);
				*line = NULL;
			}
			return (ret);
		}
	}
	return (1);
}
