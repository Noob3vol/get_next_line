/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 00:21:36 by iguidado          #+#    #+#             */
/*   Updated: 2020/02/07 00:22:56 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

int	get_next_line(int fd, char **line)
{
	static char		buffer[BUFFER_SIZE + 1];
	int				ret;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	*line = NULL;
	while (!ft_dump_line(buffer, line))
	{
		if ((ret = read(fd, buffer, BUFFER_SIZE)) < 1)
		{
			if (!*line)
			{
				*line = (char *)malloc(sizeof(char));
				**line = 0;
			}
			return (ret);
		}
	}
	return (1);
}
